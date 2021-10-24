#include "testScanner.h"
#include <iostream>
using namespace std;

void testScan(int fsa_table[8][11], vector<char> vec) {
    //declarations
    tokenType token;
    int last_position = 0;
    int new_position = 0;
    int line_number = 1;

    //iterate through the vector
    for(int i = 0; i < vec.size();) {
        token = scanner(fsa_table, vec, last_position);
        token.char_counter--;
        new_position = token.char_counter;
        i = new_position;
        
        //increment line number when '\n' is seen
        for(int j = last_position; j < new_position; j++) {
            if(vec[j] == '\n') {
                line_number++;
            }
        }
    
        //print output
        if(token.return_token != "") {
            if(token.return_token == "EOFtk") {
                cout << token.return_token << " " << token.token_str << endl;
                break;
            }
            else {
                cout << token.return_token << " " << token.token_str << " " << line_number << endl;
            }
        }

        last_position = new_position;
    }

    if(token.return_token != "EOFtk") {
        token.return_token = "EOFtk";
        cout << token.return_token << endl;
    }

}