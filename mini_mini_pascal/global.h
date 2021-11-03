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
#define ENDWHILE 263
#define EOS	'\0'
#define ID	264
#define IF 265
#define MOD	266
#define NONE	-1
#define NUM	267
#define READ 268
#define THEN 269
#define WHILE 270
#define WRITE 271

struct entry {
	char *lexptr;
	int token;
};

extern FILE *fp;
extern char scanword[];

#endif
