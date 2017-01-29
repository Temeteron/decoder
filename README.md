#A decoder of encrypted text in C using ASCII

Input: a txt file, max characters of file 1024, if there are more they are ignored.

Decode with the usual technique of "key-distance"

File "decoder.c":

1) Reads char-by-char a text from keyboard until it finds EOF or exeeds the length of text that is permitted

2) Text is saved in the proper vector

3) Counts the number of hits for each printable char

4) Find the char with the highest number of hits

5) Calculate the "key"

6) Print message(t is the decoded text)

	KEY: k

	TEXT: t

File "idiotdecoder.c"
	
	"decoder.c" decodes text with a mathematical function, 
	but this decoder does this with an iteration which is less efficient

Makefile commands

	make: compiles code
	clear: deletes files
	make run: executes prog without args

Run with args, executable file is "decoder", input file encoded.txt, save the decoded text in myout1.txt

	./decoder < encoded.txt > myout1.txt

In folder examples there are files to test the algorithm

	"encoded.txt" is the encrypted
	"decoded.txt" is the decoded text

Compare files

	diff -b myout1.txt stdout1.txt
