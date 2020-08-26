# utility-tools
**Includes useful tools I have used to debug my projects**

To use these tools first use your favourite shell to run compile.sh script:
```
chmod u+x compile.sh
./compile.sh
```

## read_binary.cpp
Writes all of the bytes of the file to the stream as zeros and ones. This might be useful if you are working with binary files. 
* if the file size is high please divert the stream to a text file
to use it run the command below:
```
./read_binary {{filename}}
```
## read_bytes.cpp
Writes the file's bytes as zeros and ones. This might be useful if you are working with binary file operations as well.

It has 5 commands:
1. read next byte
2. read last byte
3. Go from HERE to N'th byte and read
4. Go from START to N'th byte and read
5. Go from END to N'th byte and read

to use it run the command below:
```
./read_bytes {{filename}}
```
