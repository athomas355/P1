#include "scanner.h"
#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

tokenType scanner(int fsa_table[8][11], vector<char> vec, int position) {
    //declarations
    int state = 0;
    int next_state;
    char current_char = vec[position];
    int col_num;   
    tokenType token;
    token.char_counter = position;
    string keywords[] = {"Begin", "End", "Repeat", "If", "Then", "Let", "Hop", "Mark", "Var", "Return", "See", "Scribe", "Code"};
    
    //while final state is not reached 
    while (state < 1000) {
        token.char_counter++;

        //if statements to determine what current char is
        //white space
        if(current_char == ' ') {
            col_num = 1;
        }
        //new line
        if(current_char == '\n') {
            col_num = 1;
        }
        //uppercase letters
        if(isupper(current_char)) {
            col_num = 2;
        }
        //lowercase letters
        if(islower(current_char)) {
            col_num = 3;
        }
        //number
        if(isdigit(current_char)) {
            col_num = 4;
        }
        //operator
        if(current_char == '+' || current_char == '^' || current_char == '#' || current_char == '.' || current_char == '[' || current_char == ']' || current_char == ';') {
            col_num = 5;
        }
        //double operator
        if(current_char == ':') {
            col_num = 6;
        }
        //double operator
        if(current_char == '<') {
            col_num = 7;
        }   
        //double operator
        if(current_char == '=') {
            col_num = 8;
        }
        //double operator
        if(current_char == '&') {
            col_num = 9;
        }
        //comment
        if(current_char == '%') {
            col_num = 10;
        }
        //EOF
        if(position >= vec.size()) {
            col_num = 0;
        }
        
        //figure out what state is next from fsa table
        next_state = fsa_table[state][col_num];
 
        //error if invalid character was read
        if(next_state == -1) {
            printf("ERROR\n");
            exit(-1);
        }

        //switch statement to determine final state
        switch(next_state) {
            case 1001:
                token.return_token = "EOFtk";
                return token;

            case 1002:
                for(string S: keywords) {
                    if(token.token_str == S) {
                        token.return_token = "Keyword";
                        return token;
                    }
                }
                token.return_token = "Identifier";
                return token; 

            case 1003:
                token.return_token = "Number";
                return token;

            case 1004:
                token.return_token = "Operator";
                return token;

            case 1005: 
                token.return_token = "Operator";
                return token;

            case 1006:
                token.return_token = "Operator";
                return token;

            case 1007:
                token.return_token = "Operator";
                return token;

            case 1008: 
                token.return_token = "Operator";
                return token;

            case 2000:
                //if '%' then loop until second '%' is seen
                while(vec[token.char_counter] != '%') {
                    token.char_counter++;
                }
                token.char_counter += 2;
                return token;
    
            //if final state isn't reached then look to next char then repeat loop until final state is reached
            default:
                if(!isspace(current_char) && current_char != '\n') {
                    token.token_str.push_back(current_char);
                }
                state = next_state;
                position++;
                
                current_char = vec[position];
        }
    }
    return token;
}