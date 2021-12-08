#include"global.hpp"

#include"emitter.hpp"
#include"error.hpp"
#include"lexer.hpp"
#include"parser.hpp"
#include"symbol.hpp"

int lookahead;
int tmp_tokenval = NONE;

void parse() {
  lookahead = lexan();
  stmt();
  // ;区切り
  while (lookahead != DONE) { // 式;という形のみ :=を認識できるように
    match(';');
    stmt();
  }
}

void stmt() {
  if (lookahead == ID) {
    match(ID); // 先読み
    if (lookahead == ASSIGN) { // :
      tmp_tokenval = tokenval; // 左辺の文字を記録
      match(ASSIGN); // :=の次の文字を読む
      expr();
      emit("STR ", ID, tmp_tokenval);
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
    int ujp_line = sz(ans);
    match(WHILE);
    // printf("label test\n");
    cond();
    // printf("gofalse out\n");
    ans.eb("CJP ");
    match(DO);
    while (lookahead != ENDWHILE) {
      stmt();
      match(';');
    }
    ans.eb("UJP " + to_string(ujp_line));

    for (int i = sz(ans) - 1; i >= 0; --i) {
      if (ans[i].substr(0, 3) == "CJP") {
        ans[i] += to_string(sz(ans));
        break;
      }
    }

    match(ENDWHILE); // 上がってmache(";")
    // printf("goto test\n");
    // printf("label out\n");
  } else if (lookahead == IF) {
    match(IF);
    cond();
    ans.eb("gofalse outif");
    match(THEN);
    stmt();
    ans.eb("label outif");
  } else if (lookahead == READ) {
    match(READ);
    match('(');
    emit("GET ", ID, tokenval);
    match(ID);
    match(')');
  } else if (lookahead == WRITE) {
    match(WRITE);
    match('(');
    emit("PUT ", ID, tokenval);
    match(ID);
    match(')');
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
      emit("LDC ", NUM, tokenval);
      match(NUM);
      break;
    case ID:
      emit("LOD ", ID, tokenval);
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
