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


## Performace and Analysis

For the performance testing, timing was performed on all three of the functions described above, and then layed out in table.
The encoded file size was also included to compare to the original file size. Note, querying didn't need to performed on multiple 
inputs because look up in a map is constant time so it doesn't matter what the word is.

| File | Encode Time | Encode Size | Decode Time | Query Time |
|----|-----|-----|-----|------|
| Small-Size-Column.txt(932KB) | 0.1452 sec | 719KB | 0.7841 sec | 0.1500 sec | 
| Medium-Size-Column.txt(9,382KB) | 1.7120 sec | 8,376KB | 7.8340 sec | 1.9217 sec |
| Large-Size-Column.txt(184,132KB) | 46.3001 sec | 198,070KB | 173.0568 sec | 55.2473 sec |

Using the data provided in the table above, it becomes clear that as the size of the original file increases so does the time.
One important thing to note, the number of unique words in the column data have a big impact on the encoding size, at least for
how we implemented it, which is why the encoded large file had a larger file size then the original. The query lookup time is
also effected by the number of unique words in the column. Otherwise, everything else was standard because to process the data
every line needed to be parsed over giving it at least an `O(n)` runtime. 

## Conclusion

Overall, the encoder and decoder worked as expected. In future implementations, a B-Tree using prefix encoding would be best because it can encode the file to an even smaller size, but it requires a lot of time to implement and will most likely decrease the runtime in order to re-balance the tree.
