#!/bin/bash

CC=gcc
CF=-c -Wextra -Wall
DF=-DDEBUG

src_files=$(shell ls *.c)
obj_files=$(src_files:.c=.o)

app: $(obj_files)
	$(CC) -o ../app $(obj_files) $(DF)

%.o: %.c $(shell ls *.h)
	$(CC) $(CF) $<

clean:
	rm *.o
	clear
	rm ../app

run:
	../app


