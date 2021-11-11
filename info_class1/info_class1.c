// add ()

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int lookahead;

void expr();

void error() {
  printf("syntax error\n");
  exit(1);
}


void match(int t) { // get next char
  if (lookahead == t) {
    lookahead = getchar();
    // printf("\"%c\"\n", lookahead); // last "\n"
  } else {
    error();
  }
}

void factor() {
  if (isdigit(lookahead)) {
    putchar(lookahead); // 先に出力してからlookahead変えないと
    match(lookahead);
  } else if (lookahead == '(') {
    match(lookahead);
    expr();
  } else {
    error();
  }
}

void term() { // 項は要素を*, /で結んだもの
  factor();
  while (1) {
    if (lookahead == '*') {
      match('*');
      factor();
      putchar('*');
    } else if (lookahead == '/') {
      match('/');
      factor();
      putchar('/');
    } else if (lookahead == '+' || lookahead == '-' || lookahead == '\n') {
      break;
    } else if (lookahead == ')') {
      match(lookahead);
      break;
    } else {
      error();
    }
  }
}

void expr() { // 式は項を+, -で結んだもの
  term(); // *, /が最初に来たらここで処理
  while (1) {
    if (lookahead == '+') {
      match('+');
      term();
      putchar('+');
    } else if (lookahead == '-') {
      match('-');
      term();
      putchar('-');
    } else if (lookahead == '\n') {
      break;
    } else { // changed
      error();
    }
  }
}


int main(void) {
  lookahead = getchar();
  expr();
  putchar('\n');
  return 0;
}
