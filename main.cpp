#include "RegularExpression.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
  // Test 1
  cout << "Input:\nab+c.aba.*.bac.+.+*\nabacb\nOutput:\n";
  cout << MaxPrefix("ab+c.aba.*.bac.+.+*", "abacb") << '\n' << '\n';

  // Test 2
  cout << "Input:\nacb..bab.c.*.ab.ba.+.+*a.\nacbac\nOutput:\n";
  cout << MaxPrefix("acb..bab.c.*.ab.ba.+.+*a.", "acbac") << '\n' << '\n';

  // Test 3
  cout << "Input:\na*b.bc*.+*\naaabbccc\nOutput:\n";
  cout << MaxPrefix("a*b.bc*.+*", "aaabbccc") << '\n' << '\n';

  // Test 4
  cout << "Input:\nab.*a.c.a*bc+*.c.+*a.c.\nababacaaaccab\nOutput:\n";
  cout << MaxPrefix("ab.*a.c.a*bc+*.c.+*a.c.", "ababacaaaccab") << '\n' << '\n';

  // Test 5
  cout << "Input:\ncb+a.ab.c.*+*ac.b+.\nabcbacaacb\nOutput:\n";
  cout << MaxPrefix("cb+a.ab.c.*+*ac.b+.", "abcbacaacb") << '\n' << '\n';

  // Test 6
  cout << "Input:\nab.ba.+*ba.*.bab+.c+.\ncc\nOutput:\n";
  cout << MaxPrefix("ab.ba.+*ba.*.bab+.c+.", "cc") << '\n' << '\n';

  // Test 7
  cout << "Input:\nab.c.*ca.b.*+***\nabcabccabacc\nOutput:\n";
  cout << MaxPrefix("ab.c.*ca.b.*+***", "abcabccabacc") << '\n' << '\n';

  // Test 8
  cout << "Input:\nab.*ba.*.cc.*.a*.\naa\nOutput:\n";
  cout << MaxPrefix("ab.*ba.*.cc.*.a*.", "aa") << '\n' << '\n';

  // Test 9
  cout << "Input:\na**a.b.c.a.b.a.\naabcac\nOutput:\n";
  cout << MaxPrefix("a**a.b.c.a.b.a.", "aabcac") << '\n' << '\n';

  // Test 10
  cout << "Input:\nabb.*.c.ac.*ba.*.c.+aa.a.*b.+*a.a.\nacccbbaaac\nOutput:\n";
  cout << MaxPrefix("abb.*.c.ac.*ba.*.c.+aa.a.*b.+*a.a.", "acccbbaaac") << '\n'
       << '\n';
}