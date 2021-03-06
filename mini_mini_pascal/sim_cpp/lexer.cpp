#include "global.hpp"
#include "symbol.hpp"
#include "error.hpp"

char lexbuf[BSIZE];
int lineno = 1; // こんなとこにduplicate
int tokenval = NONE;

int lexan() {
  while(1) {
    // int t = getchar();
    int t = fgetc(fp);
    // printf("lexan %c\n", t);
    if (t == ' ' || t == '\t') {

    } else if ( t == '\n') {
      ++lineno;
    } else if (isdigit(t)) {
      // ungetc(t, stdin);
      ungetc(t, fp);
      // scanf("%d", &tokenval); // scanf_s("%d, &tokenval") in Windows
      tokenval = 0;
      while (isdigit(t = fgetc(fp))) {
        t -= '0';
        tokenval *= 10;
        tokenval += t;
      }
      ungetc(t, fp);
      return NUM;
    } else if (isalpha(t)) { // tが英字 文字列の先頭 beginとかを別処理
      int p,b = 0;
      while (isalnum(t)) { // tが英数字 '0'-'9','A'-'Z','a'-'z' 2文字目以降
        lexbuf[b] = t;
        // t = getchar();
        t = fgetc(fp);
        ++b;
        if (b >= BSIZE) {
          error("compiler error");
        }
      }
      lexbuf[b] = EOS;
      if (t != EOF) {
        // ungetc(t, stdin); // whileで一つ先まで読んでるから
        ungetc(t, fp);
      }
      p = lookup(lexbuf); // すでに登録された文字列か探す
      // printf("%s %d\n", lexbuf, p);
      if (p == 0) { // 未登録
        p = insert(lexbuf, ID); // 文字列のトークンはID
      }
      // printf("lexan_isalpha %d %d\n", p, symtable[p].token);
      tokenval = p;
      return symtable[p].token;
    } else if (t == '.') {
      return DONE;
    } else if (t == ':') {
      // t = getchar();
      t = fgetc(fp);
      if (t == '=') {
        return ASSIGN;
      }
    } else { // ;
      tokenval = NONE;
      // printf("lexan else %d\n", t);
      return t;
    }
  }
}
