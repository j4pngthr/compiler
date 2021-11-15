#ifndef SYMBOL_H
#define SYMBOL_H

#include "global.hpp"

int lookup(string s);
int insert(string s, int tok);

extern struct entry symtable[];

#endif
