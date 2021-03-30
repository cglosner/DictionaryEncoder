#include <string>
#include <fstream>
#include "bTree.h"


bTree BT;

//This uncompresses the document
void extract(std::string inputName)
{
  std::ifstream file(inputName, std::ios_base::in);
  if(file.is_open())
  {
    std::string s;
    while(getline(file, s))
    {

    }
    file.close();
  }
}

//This compress the document
void locate(std::string inputName)
{
  std::ifstream file(inputName, std::ios_base::in);
  if(file.is_open())
  {
    std::string s;
    while(getline(file, s))
    {
      btInsert(BT, std::stoi(s));
    }
    file.close();
  }
}


void writeFile(std::string outputName)
{
  std::ofstream out_file(outputName, std::ios::trunc | std::ios_base::out);
  if(out_file.is_open())
  {
    //while(decomp >> size)
    //{
    //  out_file << comp;
    //}
    out_file.close();
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
    BT = btCreate();
    if(std::string(argv[1]) == "-e")
    {
      locate(std::string(argv[2]));
      writeFile(std::string(argv[3]));
    }
    else if(std::string(argv[1]) == "-d")
    {
      extract(std::string(argv[2]));
      writeFile(std::string(argv[3]));
    }
    btDestroy(BT);
  }

  //Arguements:
  //argv[1] - query
  //argv[2] - data
  if(argc == 3)
  {
    if(std::string(argv[1]) == "-q")
    {

    }
  }
}
