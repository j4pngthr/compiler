#include "global.h"
#include "init.h"
#include "parser.h"

const int BUFFER_SIZE = 256;
FILE *fp;
char scanword[256];

void main() {
  init();
  printf("ファイル名:");
  char filename[BUFFER_SIZE];
  scanf("%s", filename);
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("ファイルオープン失敗\n");
    return;
  }
  // char c;
  // while ((c = fgetc(fp)) != EOF) {
  //   fputc(c, stdin);
  //   c = getchar();
  //   printf("%c\n", c);
  // }
  // while (fgets(scanword, BUFFER_SIZE, fp) != NULL) {
  //   fputs(scanword, stdin);
  //   char s[256];
  //   scanf("%s", &s);
  //   printf("%s\n", scanword);
  // }
  // char c = fgetc(fp);
  // putchar(c);
  // c = fgetc(fp);
  // putchar(c);


  parse();
}
