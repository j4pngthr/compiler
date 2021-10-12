#include "global.h"
#include "symbol.h" // 先にsymbolをincludeしたら，構造体を定義してないのにextern出てまずい？

struct entry keywords[] = {
  "div", DIV,
  "mod", MOD,
  0, 0
};

void init() {
  struct entry *p;
  for (p = keywords; p -> token; p++) {
    insert(p -> lexptr, p -> token); // symbol.c
  }
}
