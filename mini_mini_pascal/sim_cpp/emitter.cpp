#include "global.hpp"
#include "symbol.hpp"

void emit(int t, int tval) {
  switch(t) {
    case '+':
      printf("ADD\n");
      break;
    case '<':
      printf("LES\n");
      break;
    case '-': case '*': case '/': case '>': case '=':
      printf("%c\n", t);
      break;
    case DIV:
      printf("DIV\n");
      break;
    case MOD:
      printf("MOD\n");
      break;
    case NUM:
      printf("%d\n", tval);
      break;
    case ID:
      printf("%d\n", symtable[tval].lexptr[0] - 'a');
      break;
    default:
      printf("token %d, tokenval %d\n", t, tval);
  }
}
