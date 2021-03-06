#include <iostream>
#include <vector>
#include <string>
#include <deque>

using std::vector;
using std::string;
using std::deque;
using std::cin;
using std::cout;

string main_string;
size_t lenght;

struct Reg_exp {
  // init by chars - a/b/c
  explicit Reg_exp(char symbol)
      : prefixes(lenght, vector<size_t>(lenght)),
        full_words(lenght, vector<size_t>(lenght)), has_empty_word(false) {
    for (size_t i = 0; i < lenght; ++i) {
      if (main_string[i] == symbol) {
        prefixes[i][i] = 1;
        full_words[i][i] = 1;
      }
    }
  }
  // req1 + reg2
  Reg_exp &operator+=(const Reg_exp &right) {
    for (size_t i = 0; i < lenght; ++i) {
      for (size_t j = 0; j < lenght; ++j) {
        this->full_words[i][j] = std::max(this->full_words[i][j], right.full_words[i][j]);
        this->prefixes[i][j] = std::max(this->prefixes[i][j], right.prefixes[i][j]);
      }
    }
    this->has_empty_word = std::max(this->has_empty_word, right.has_empty_word);
    return *this;
  }
  // reg1 * reg2
  Reg_exp &operator*=(const Reg_exp &right) {
    vector<vector<size_t>> new_prefixes(lenght, vector<size_t>(lenght));
    for (size_t k = 0; k < lenght; ++k) {
      for (size_t i = k; i < lenght; ++i) {
        if (this->prefixes[k][i] == 1 || (this->has_empty_word && right.prefixes[k][i] == 1)) {
          new_prefixes[k][i] = 1;
          continue;
        }
        for (size_t j = k; j < i; ++j) {
          if (this->full_words[k][j] && right.prefixes[j + 1][i]) {
            new_prefixes[k][i] = 1;
            break;
          }
        }
      }
    }

    vector<vector<size_t>> new_full_words(lenght, vector<size_t>(lenght));
    for (size_t k = 0; k < lenght; ++k) {
      for (size_t i = k; i < lenght; ++i) {
        if ((this->full_words[k][i] && right.has_empty_word) || (this->has_empty_word && right.full_words[k][i])) {
          new_full_words[k][i] = 1;
          continue;
        }
        for (size_t j = k; j < i; ++j) {
          if (this->full_words[k][j] && right.full_words[j + 1][i]) {
            new_full_words[k][i] = 1;
            break;
          }
        }
      }
    }
    this->full_words = new_full_words;
    this->prefixes = new_prefixes;
    this->has_empty_word = this->has_empty_word * right.has_empty_word;
    return *this;
  }
  // (reg)*
  Reg_exp &operator*() {
    vector<vector<size_t >> new_prefixes(lenght, vector<size_t>(lenght));

    for (int i = static_cast<int>(lenght - 1); i >= 0; --i) {
      for (int k = i; k >= 0; --k) {
        if (this->prefixes[k][i]) {
          new_prefixes[k][i] = 1;
          continue;
        }
        for (size_t j = k; j < i; ++j) {
          if (this->full_words[k][j] && new_prefixes[j + 1][i]) {
            new_prefixes[k][i] = 1;
            break;
          }
        }
      }
    }

    vector<vector<size_t>> new_full_words(lenght, vector<size_t>(lenght));

    for (int i = static_cast<int>(lenght - 1); i >= 0; --i) {
      for (int k = i; k >= 0; --k) {
        if (this->full_words[k][i]) {
          new_full_words[k][i] = 1;
          continue;
        }
        for (size_t j = k; j < i; ++j) {
          if (this->full_words[k][j] && new_full_words[j + 1][i]) {
            new_full_words[k][i] = 1;
            break;
          }
        }
      }
    }

    this->full_words = new_full_words;
    this->prefixes = new_prefixes;
    this->has_empty_word = true;
    return *this;
  }

  // два вектора: full_words[i][j] == 1 <=> в регулярке есть СЛОВО u[i..j]
  //  prefixes[i][j] == 1 <=> регулярка задает слово, префиксом которого является u[i..j]

  vector<vector<size_t>> full_words;
  vector<vector<size_t>> prefixes;
  bool has_empty_word;
};

void case_symbol(char symbol, deque<Reg_exp> &deq_reg) {
  deq_reg.emplace_back(symbol);
}
void case_addition(deque<Reg_exp> &deq_reg) {
  deq_reg[deq_reg.size() - 2] += deq_reg.back();
  deq_reg.pop_back();
}

void case_concat(deque<Reg_exp> &deq_reg) {
  deq_reg[deq_reg.size() - 2] *= deq_reg.back();
  deq_reg.pop_back();
}
void case_star(deque<Reg_exp> &deq_reg) {
  *deq_reg.back();
}

void update_reg_deque(char symbol, deque<Reg_exp> &deq_reg) {
  if (symbol == 'a' || symbol == 'b' || symbol == 'c') {
    case_symbol(symbol, deq_reg);
  } else if (symbol == '+') {
    case_addition(deq_reg);
  } else if (symbol == '.') {
    case_concat(deq_reg);
  } else if (symbol == '*') {
    case_star(deq_reg);
  }
};

int main() {
  deque<Reg_exp> deq_reg;
  string reg;
  cin >> reg >> main_string;
  lenght = main_string.size();
  for (char i : reg) {
    update_reg_deque(i, deq_reg);
  }
  for (int i = static_cast<int>(lenght - 1); i >= 0; --i) {
    if (deq_reg.back().prefixes[0][i] == 1) {
      cout << i + 1;
      return 0;
    }
  }
  cout << "No";
  return 0;
}
