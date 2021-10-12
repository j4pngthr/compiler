#include "global.h"
#include "error.h"

#define STRMAX  999
#define SYMMAX  100

char lexemes[STRMAX];
int lastchar = -1; // lexemesで最後に使用した位置
struct entry symtable[SYMMAX];
int lastentry = 0; // symtableで最後に使用した位置 p73

int lookup(char s[]) {
  for (int p = lastentry; p > 0; p = p -1) {
    if (strcmp(symtable[p].lexptr, s) == 0) {
      return p;
    }
  }
  return 0;
}

// 単語の追加
// sのエントリの位置を返す
int insert(char s[], int tok) {
  int len = strlen(s);
  if (lastentry + 1 >= SYMMAX) {
    error("symbol table full");
  }
  if (lastchar + (len + 1) >= STRMAX) { // +1はEOS
    error("lexemes array full");
  }
  ++lastentry;
  // symtableへの追加
  symtable[lastentry].token = tok;
  symtable[lastentry].lexptr = &lexemes[lastchar + 1]; // 最後に使用した位置の次の位置へのポインタ p73
  lastchar += len + 1; // +1はEOS
  strcpy(symtable[lastentry].lexptr, s); // lexemesに書き込まれる
  // for (int i = 0; i < 10; ++i) printf("%d%c ", i, lexemes[i]);
  // putchar('\n');
  return lastentry;
}
