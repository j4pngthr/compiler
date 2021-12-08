#include"global.hpp"
#include"error.hpp"

void calc(string);
void exeIstr(string, int);
bool isOpr(string);
// program counter
int pgm_ctr = 0;
// code address
int max_cod_add = 0;
// stack pointer
int stk_ptr = 0;
stack<int> stk;
vector<int> mem(26);

// command
void calc(string com) {
  if (com == "ADD") {
    ++pgm_ctr;
    { // stackの処理
      int a = stk.top();
      stk.pop();
      if (stk.empty()) error("stack is empty");
      stk.top() += a;
      --stk_ptr;
    }
  }
}

// execute instruction
void exeIstr(string com, int num) {
  if (isOpr(com)) {
    if (num != -1) error("num is not equal to -1");
    calc(com);
    return;
  }
  if (com == "GET") {
    ++pgm_ctr;
    cin >> mem[num];
  } else if (com == "LOD") {
    ++pgm_ctr;
    ++stk_ptr;
    stk.push(mem[num]);
  } else if (com == "LDC") {
    ++pgm_ctr;
    ++stk_ptr;
    stk.push(num);
  } else if (com == "STR") {
    ++pgm_ctr;
    --stk_ptr;
    mem[num] = stk.top();
    stk.pop();
  } else if (com == "PUT") {
    ++pgm_ctr;
    if (num < 0 && num >= 26) error(to_string(num) + "is wrong address of memory");
    cout << mem[num] << endl;
  } else {
    error("no command, " + com);
  }
}

// is operator
bool isOpr(string com) {
  if (com == "ADD" || com == "SUB" || com == "MLT" || com == "DIV") {
    return 1;
  }
  return 0;
}

void objExe() {
  ifstream ifs("./obj.txt");
  if (ifs.fail()) error("Failed to open file.");
  {
    string str;
    while (getline(ifs, str)) {
      int num = -1;
      if (!isOpr(str)) {
        num = stoi(str.substr(4));
      }
      string com = str.substr(0, 3);
      if (isOpr(com)) cerr << com << endl;
      else cerr << com << " " << num << endl;

      exeIstr(com, num);
    }
  }
  return;
}
