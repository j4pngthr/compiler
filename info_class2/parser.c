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
      match(ASSIGN); // :=の次の文字を読む
      expr();
      printf(":=\n");
    }
  } else if (lookahead == BEGIN) {
    match(BEGIN);
    while (lookahead != END) {
      stmt();
      // printf("parser_begin %d\n", lookahead);
      match(';');
      // printf("%d\n", lookahead);
    }
    match(END);
  } else if (lookahead == WHILE) {
    match(WHILE);
    printf("label test\n");
    cond();
    printf("gofalse out\n");
    match(DO);
    stmt();
    printf("goto test\n");
    printf("label out\n");
  } else if (lookahead == IF) {
    match(IF);
    cond();
    printf("gofalse outif\n");
    match(THEN);
    stmt();
    printf("label outif\n");
  } else {
    error("invalid statement");
  }
}

void cond() { // 条件式
  int t;
  expr();
  // printf("%c\n", lookahead);
  while(1) {
    switch (lookahead) {
      case '<': case '>': case '=':
        t = lookahead;
        match(lookahead);
        expr();
        emit(t, NONE);
        continue;
      default:
        return;
    }
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
      error("syntax error(factor)");
  }
}

// 次の単語を読む
void match(int t) {
  if (lookahead == t) {
    // putchar('a');
    // putchar('\n');
    lookahead = lexan();
  } else {
    error("syntax error(match)");
  }
}
