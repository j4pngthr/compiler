#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include"emitter.h"
#include"error.h"
#include"init.h"
#include"lexer.h"
#include"parser.h"
#include"symbol.h"

#define BSIZE	128
#define NONE	-1
#define EOS	'\0'

#define NUM	256
#define DIV	257
#define MOD	258
#define ID	259
#define DONE	260

struct entry {
	char *lexptr;
	int token;
};

extern int tokenval;
extern int lineno;

extern struct entry symtable[];
