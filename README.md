# count

The premise of this project is to read millions of lines from a text file, and insert them into a hash table of size 100 using linked lists to avoid collisions.

It then outputs the number of unique lines in the original text file.

Example:

file2.txt contains:
0x7f1a9804ae19
0x7f1a9804ae1c
0x7f1a9804ae1c
0x7f1a9804ae19
0x7f1a9804ae16
0x7f1a9814ae1c

./count file2.txt
4
