# Dictionary Encoder

## Test Bench

Computer Information
- OS: Windows 10 Pro
- RAM: 64GB 
- CPU: i7-5960X @ 3.00GHz
- GPU: 8GB
- SSD: 1TB

## Overview

This project implements a dictionary encoder using a map to do so. It has several
functions: encode the data and print to an output file, decode an encoded file and print to
an output file, and finally query data to find how many occurances there are in the encoded file.

## Code Description

This code has three main functions: `extract`, `locate`, and `query`. Those three will be explained 
in sections below according to there use. Two additional functions, `writeDecoded` and `writeEncoded`, 
are used to write the decoded data and encoded data to their respective output files. They are both very 
straight forward so they don't need additional explaination. Before the functions are explained, to run the
code there are several options once it is compiled. To compile the code:

```
g++ dict.cpp -g -o dict.out
```

Then to encode a file using the code:

```
./dict.out -e Input-File.txt Output-File.txt
```

To decode a file:

```
./dict.out -d Encoded-File.txt Output-File.txt
```

Finally, to query data:

```
./dict.out -q Encoded-File.txt data
```

where the Encoded-File.txt needs to be an encoded file to work properly, and `data` is the word/string
that you are trying find the number of occurances of.

### Encode File

To encode data, the `locate` function is used, which simply runs through the file line by line
and maps the word/string to a vector of line numbers. 

### Decode File

To decode data, the `extract` function is used, which operates almost identical to the `locate` function above
except it operates in the opposite direction. Another thing to note, a second map is used to map line numbers to 
strings/words that way it is easier to write to file later.

### Query File

To query data, the `extract` function is used first to populate the dictionary and then the `query` function is used,
which simply looks up the string and prints out the length of the line vector.


## Performace

## Analysis

## Conclusion
