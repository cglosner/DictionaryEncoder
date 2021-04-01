#include <string>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <sys/times.h>
#include <time.h>
#include "sys/types.h"
#include "sys/sysinfo.h"

std::map<std::string, std::vector<long int>> dictionary;
std::map<long int, std::string> list;

//This uncompresses the document
void extract(std::string inputName)
{
  std::ifstream file(inputName, std::ios_base::in);
  if(file.is_open())
  {
    std::string line;
    while(getline(file, line))
    {
      std::istringstream ss(line);
      std::string s;
      std::string word;
      std::vector<long int> tmp;
      bool first = true;
      while(ss >> s)
      {
        if(first)
        {
          word = s;
          first = false;
        }
        else
        {
          list.insert(std::pair<long int, std::string>((long int)std::stoi(s), word));
          tmp.push_back((long int)std::stoi(s));
        }
      }
      dictionary.insert(std::pair<std::string, std::vector<long int>>(word, tmp));
    }
    file.close();
  }
}

//write the decoded data from the specially
//constructed list
void writeDecoded(std::string outputName)
{
  std::ofstream out_file(outputName, std::ios::trunc | std::ios_base::out);
  if(out_file.is_open())
  {
    for(int i = 0; i < list.size(); i++)
    {
      out_file << list[i] << std::endl;
    }
    out_file.close();
  }
}

//This compress the document
void locate(std::string inputName)
{
  std::ifstream file(inputName, std::ios_base::in);
  if(file.is_open())
  {
    std::string s;
    long int line = 0;
    while(getline(file, s))
    {
      if(dictionary.count(s) > 0)
      {
        dictionary.at(s).push_back(line);
      }
      else
      {
        std::vector<long int> tmp{line};
        dictionary.insert(std::pair<std::string, std::vector<long int>>(s, tmp));
      }
      line++;
    }
    file.close();
  }
}

//write the encoded data
void writeEncoded(std::string outputName)
{
  std::ofstream out_file(outputName, std::ios::trunc | std::ios_base::out);
  if(out_file.is_open())
  {
    std::map<std::string, std::vector<long int>>::iterator itr;
    for(itr = dictionary.begin(); itr != dictionary.end(); itr++)
    {
      out_file << itr->first << " ";
      std::vector<long int> tmp = itr->second;
      for(int i = 0; i < tmp.size(); i++)
      {
        out_file << tmp[i] << " ";
      }
      out_file << std::endl;
    }
    out_file.close();
  }
}

//Locate the number of occurances of a word
//from dictionary
void query(std::string data)
{
  if(dictionary.count(data) > 0)
  {
    std::cout << data << " had " << dictionary.at(data).size() << " occurances." << std::endl;
  }
  else
  {
    std::cout << "Data isn't contained in file" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  //Arguements:
  //argv[1] - encode/decode
  //argv[2] - input file
  //argv[3] - output file

  if(argc == 4)
  {
    if(std::string(argv[1]) == "-e")
    {
      auto start = std::chrono::high_resolution_clock::now();
      locate(std::string(argv[2]));
      writeEncoded(std::string(argv[3]));
      auto stop = std::chrono::high_resolution_clock::now();
      double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
      duration /= 1e6;
      std::cout << "Encode Runtime: " << std::fixed << duration << std::setprecision(9);
      std::cout << "sec" << std::endl;
    }
    else if(std::string(argv[1]) == "-d")
    {
      auto start = std::chrono::high_resolution_clock::now();
      extract(std::string(argv[2]));
      writeDecoded(std::string(argv[3]));
      auto stop = std::chrono::high_resolution_clock::now();
      double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
      duration /= 1e6;
      std::cout << "Decode Runtime: " << std::fixed << duration << std::setprecision(9);
      std::cout << "sec" << std::endl;
    }
  }

  //Arguements:
  //argv[1] - query
  //argv[2] - file
  //argv[3] - data
  if(argc == 4)
  {
    if(std::string(argv[1]) == "-q")
    {
      auto start = std::chrono::high_resolution_clock::now();
      extract(std::string(argv[2]));
      query(std::string(argv[3]));
      auto stop = std::chrono::high_resolution_clock::now();
      double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
      duration /= 1e6;
      std::cout << "Query Runtime: " << std::fixed << duration << std::setprecision(9);
      std::cout << "sec" << std::endl;
    }
  }
}
