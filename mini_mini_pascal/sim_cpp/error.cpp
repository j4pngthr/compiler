#include "global.hpp"
#include "lexer.hpp"

void error(string m) {
  cerr << "line " << lineno << ": " << m << endl; 
  exit(1);
}
