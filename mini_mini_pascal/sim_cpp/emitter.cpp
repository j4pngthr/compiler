#include "global.hpp"
#include "symbol.hpp"

void emit(int t, int tval) {
  switch(t) {
    case '+':
      ans.eb("ADD");
      break;
    case '<':
      ans.eb("LES");
      break;
    case '-': case '*': case '/': case '>': case '=':
      ans.eb(to_string(t));
      break;
    case DIV:
      ans.eb("DIV");
      break;
    case MOD:
      ans.eb("MOD");
      break;
    case NUM:
      ans.eb(to_string(tval));
      break;
    case ID:
      ans.eb(to_string(symtable[tval].lexptr[0] - 'a'));
      break;
    default:
      printf("token %d, tokenval %d\n", t, tval);
  }
}

void emit(string str, int t, int tval) {
  switch(t) {
    case NUM:
      ans.eb(str + to_string(tval));
      break;
    case ID:
      ans.eb(str + to_string(symtable[tval].lexptr[0] - 'a'));
      break;
    default:
      printf("token %d, tokenval %d\n", t, tval);
  }
}
