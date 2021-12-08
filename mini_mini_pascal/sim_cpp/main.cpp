#include"global.hpp"
#include"init.hpp"
#include"parser.hpp"
#include"error.hpp"

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
    error("ファイルオープン失敗\n");
  }

  parse();

  rep(i, sz(ans)) cerr << ans[i] << endl;
}
