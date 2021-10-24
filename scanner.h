#ifndef SCANNER_H
#define SCANNER_H
#include "token.h"
#include <vector>
using namespace std;

tokenType scanner(int fsa_table[8][11], vector<char> vec, int position);

#endif