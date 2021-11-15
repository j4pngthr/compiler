#include "global.h"
#include "init.h"
#include "parser.h"

const int BUFFER_SIZE = 256;
FILE *fp;
char scanword[256];
vector<string> ans;

void main() {
  init();

  // printf("ファイル名:");
  // char filename[BUFFER_SIZE];
  // scanf("%s", filename);
  char filename[] = "input_data3.txt";
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("ファイルオープン失敗\n");
    return;
  }

  parse();
}
