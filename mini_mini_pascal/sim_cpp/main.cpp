#include"global.hpp"
#include"init.hpp"
#include"parser.hpp"
#include"error.hpp"
#include"objExe.hpp"

FILE *fp;
string scanword;
vector<string> ans;

int main() {
  init();

  // printf("ファイル名:");
  // char filename[BUFFER_SIZE];
  // scanf("%s", filename);
  const char *filename = "../input_data.txt";
  if ((fp = fopen(filename, "r")) == NULL) {
    error("ファイルオープン失敗\n");
  }

  parse();

  // rep(i, sz(ans)) cerr << ans[i] << endl;
  ofstream os("./obj.txt");
  rep(i, sz(ans)) {
    os << ans[i] << endl;
  }
  os.close();

  objExe();
}
