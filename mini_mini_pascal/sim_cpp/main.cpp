#include "global.hpp"
#include "init.hpp"
#include "parser.hpp"

FILE *fp;
string scanword;
vector<string> ans;

int main() {
  init();

  // printf("ファイル名:");
  // char filename[BUFFER_SIZE];
  // scanf("%s", filename);
  const char *filename = "../input_data3.txt";
  if ((fp = fopen(filename, "r")) == NULL) {
    printf("ファイルオープン失敗\n");
    return 0;
  }

  parse();
}
