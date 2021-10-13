#include "global.h"
#include "init.h"
#include "parser.h"

const int BUFFER_SIZE = 256;
FILE *fp;

void main() {
  init();
  printf("ファイル名:");
  char filename[BUFFER_SIZE];
  scanf("%s", filename);
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("ファイルオープン失敗\n");
    return;
  }
  // while (fgets(scanword, BUFFER_SIZE, fp) != NULL) {
  //
  // }

  parse();
}
