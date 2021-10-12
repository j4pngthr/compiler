#ifndef SYMBOL_H
#define SYMBOL_H

#include"global.h"

int lookup(char s[]);
int insert(char s[], int tok);

extern struct entry symtable[];

#endif
