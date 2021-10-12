#include "global.h"

char  lexbuf[BSIZE];
int  lineno = 1;
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
        if (b >= BSIZE)
          error("compiler error");
      }
      lexbuf[b] = EOS;
      if (t !=EOF) {
        ungetc(t, stdin);
      }
      p = lookup(lexbuf);
      if (p == 0) {
        p = insert(lexbuf, ID);
      }
      tokenval = p;
      return symtable[p].token;
    } else if (t == EOF) {
      return DONE;
    } else {
      tokenval = NONE;
      return t;
    }
  }
}
