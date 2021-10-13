#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BSIZE	128
#define NONE	-1
#define EOS	'\0'

#define NUM	256
#define DIV	257
#define MOD	258
#define ID	259
#define DONE	260
#define ASSIGN 261
#define BEGIN 262
#define WHILE 263
#define IF 264
#define END 265

struct entry {
	char *lexptr;
	int token;
};

#endif
