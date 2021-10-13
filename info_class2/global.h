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
#define DO 260
#define DONE	261
#define END 262
#define EOS	'\0'
#define ID	263
#define IF 264
#define MOD	265
#define NONE	-1
#define NUM	266
#define WHILE 267

struct entry {
	char *lexptr;
	int token;
};

// extern FILE *fp;
// extern char scanword[];

#endif
