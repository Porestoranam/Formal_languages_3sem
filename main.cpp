#include "RegularExpression.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
  deque<Reg_exp> deq_reg;
  string reg;
  string main_string_2;
  cin >> reg >> main_string_2;
  cout << MaxPrefix(reg, main_string_2);
}
