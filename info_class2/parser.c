#include "global.h"

int lookahead;

void parse();
void expr();
void term();
void factor();
void match(int t);

void parse() {
  lookahead = lexan();
  while (lookahead != DONE) {
    expr();
    match(';');
  }
}

void expr() {
  int t;
  term();
  while(1)
    switch (lookahead) {
    case '+': case '-':
      t = lookahead;
      match(lookahead);
      term();
      emit(t, NONE);
      continue;
    default:
      return 0;
    }
}

void term() {
  factor();
  while(1) {
    switch (lookahead) {
      case '*': case '/': case DIV: case MOD:
        int t = lookahead;
        match(lookahead);
        factor();
        emit(t, NONE);
        continue;
      default:
        return;
    }
  }
}

void factor() {
  switch(lookahead) {
    case '(':
      match('(');
      expr();
      match(')');
      break;
    case NUM:
      emit(NUM, tokenval);
      match(NUM);
      break;
    case ID:
      emit(ID, tokenval);
      match(ID);
      break;
    default:
      error("syntax error");
  }
}

void match(int t) {
  if (lookahead == t) {
    lookahead = lexan();
  } else {
    error("syntax error");
  }
}
