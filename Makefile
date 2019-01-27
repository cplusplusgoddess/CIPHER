
############################################
#  Author: 	Amber Rogowicz
#  File	:	Makefile  for building pyramid 
#  Date:	July 2018

CC = g++
# Note: the following are OSX platform flags
# CC = clang++
CFLAGS  = -v -Wall -std=c++0x -ggdb -fPIC

# adjust flags as necessary for your platform
#CFLAGS  = -g -Wall -fPIC -std=c++11 

#LDFLAGS =  -lpthread

all: test.o  test

test: test.o  
	$(CC) $(CFLAGS) $(LDFLAGS) test.o -o test

test.o: test.cpp cipher.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o



clean:
	rm -rf *.o  test
