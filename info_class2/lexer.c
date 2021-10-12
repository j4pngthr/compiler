#include "global.h"
#include "symbol.h"
#include "error.h"

char  lexbuf[BSIZE];
int  lineno = 1; // こんなとこにduplicate
int  tokenval = NONE;

int lexan() {
  while(1) {
    int t = getchar();
    if (t == ' ' || t == '\t') {

    } else if ( t == '\n') {
      lineno = lineno + 1;
    } else if (isdigit(t)) {
      ungetc(t, stdin);
      scanf("%d", &tokenval); // scanf_s("%d, &tokenval") in Windows
      return NUM;
    } else if (isalpha(t)) {
      int p,b = 0;
      while (isalnum(t)) {
        lexbuf[b] = t;
        t = getchar();
        b = b + 1;
        if (b >= BSIZE) {
          error("compiler error");
        }
      }
      lexbuf[b] = EOS;
      if (t != EOF) {
        ungetc(t, stdin);
      }
      p = lookup(lexbuf); // すでに登録された文字列か探す
      if (p == 0) { // 未登録
        p = insert(lexbuf, ID);
      }
      tokenval = p;
      return symtable[p].token;
    } else if (t == EOF) {
      return DONE;
    } else if (t == ':') {
      t = getchar();
      if (t == '=') {
        return ASSIGN;
      }
    } else {
      tokenval = NONE;
      return t;
    }
  }
}
