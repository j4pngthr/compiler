#include "global.h"
#include "symbol.h" // 先にsymbolをincludeしたら，構造体を定義してないのにextern出てまずい？

struct entry keywords[] = {
  "div", DIV,
  "mod", MOD,
  "begin", BEGIN,
  "end", END,
  "if", IF,
  "while", WHILE,
  0, 0 // initのforの継続条件で0になって終了
};

void init() {
  struct entry *p;
  for (p = keywords; p -> token; p++) {
    insert(p -> lexptr, p -> token); // symbol.c
  }
}
