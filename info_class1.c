#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int lookahead;

void error() {
	printf("syntax error\n");
	exit(1);
}


void match(int t) {
	if (lookahead == t) {
		lookahead = getchar();
		// printf("\"%c\"\n", lookahead); // last "\n"
	} else {
		error();
	}
}

void term() {
	if (isdigit(lookahead)) {
		putchar(lookahead);
		match(lookahead);
	} else {
		error();
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
		} else { // "\n", (work with garbage input)
			break;
		}
	}
}


int main(void) {
	lookahead = getchar();
	expr();
	putchar('\n');
	return 0;
}

