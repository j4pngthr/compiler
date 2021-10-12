// add *, /

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int lookahead;

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

void factor() { // leaf, output number and get operator
  if (isdigit(lookahead)) {
    putchar(lookahead);
    match(lookahead);
  } else {
    error();
  }
}

void term() {
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
    } else {
      error();
    }
  }
}

void expr() {
  term();
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
