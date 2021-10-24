#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

struct tokenType {
    enum tokenID {IDENT_tk, NUM_tk, KW_tk, OP_tk, EOF_tk};
    string tokenNames[5] = {"Identifier", "Number", "Keyword", "Operator", "EOFtk"};
    int lineNumber;
    int state;
    string return_token;
    string token_str;
    int char_counter = 0;
    bool newline_lookahead = false;
};

#endif