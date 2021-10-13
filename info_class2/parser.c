#include "global.h"
#include "emitter.h"
#include "error.h"
#include "lexer.h"
#include "parser.h"

int lookahead;

void parse() {
  lookahead = lexan();
  // ;区切り
  while (lookahead != DONE) { // 式;という形のみ :=を認識できるように
    stmt();
    match(';');
  }
}

void stmt() {
  if (lookahead == ID) {
    printf("lvalue ");
    emit(ID, tokenval);
    match(ID); // 先読み
    if (lookahead == ASSIGN) { // :
      match(ASSIGN);
      expr();
      printf(":=\n");
    }
  } else if (lookahead == BEGIN) {
    match(lookahead);
    while (lookahead != END) {
      stmt();
    }
    // parseに上がってmatch(;)
  } else if (lookahead == WHILE) {

  } else if (lookahead == IF) {

  } else {
    error("invalid statement");
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
        emit(t, NONE); // NONEはどうでもいい t=+or-が意味を持つ
        continue;
      default:
        return;
    }
}

void term() {
  int t;
  factor();
  while(1) {
    switch (lookahead) {
      case '*': case '/': case DIV: case MOD:
        t = lookahead;
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
      printf("push ");
      emit(NUM, tokenval);
      match(NUM);
      break;
    case ID:
      printf("rvalue ");
      emit(ID, tokenval);
      match(ID);
      break;
    default:
      error("syntax error");
  }
}

// 次の単語を読む
void match(int t) {
  if (lookahead == t) {
    lookahead = lexan();
  } else {
    error("syntax error");
  }
}
