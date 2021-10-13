#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define ASSIGN 257
#define BEGIN 258
#define BSIZE	128
#define DIV	259
#define DONE	260
#define END 261
#define EOS	'\0'
#define ID	262
#define IF 263
#define MOD	264
#define NONE	-1
#define NUM	265
#define WHILE 266

struct entry {
	char *lexptr;
	int token;
};

extern FILE *fp;


#endif
