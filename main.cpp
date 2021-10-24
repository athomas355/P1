#include "testScanner.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define MAX_STR_LENGTH 1024

//function to add char to vector
void addChar(vector<char> vec, char c) {
    vec.push_back(c);
}

int main(int argc, char* argv[]) {
    
    //declarations
    vector<char> str;
    string file_line;
    char ch;
    string line_string;
    /*
        Rows:
        0 = initial state, 1 = ID, 2 = digit, 3 = single_op, 4 = double_op, 5 = :<, 6 = :=, 7 = :&

        Columns:
        EOF, WS, Uppercase letter, Lowercaser letter, number, Single_op, :, <, =, &, %

        Final States:
        1001 = EOFtk, 1002 = IDtk/KWtk, 1003 = NUMtk, 1004-1008 = OPtk, 2000 = comment 
    */
    int fsa_table[8][11] = {
    1001, 0, 1, -1, 2, 3, 4, -1, -1, -1, 2000,                              //initial state
    1002, 1002, 1, 1, 1, 1002, 1002, 1002, 1002, 1002, 2000,                //ID state
    1003, 1003, 1003, 1003, 2, 1003, 1003, 1003, 1003, 1003, 2000,          //digit state
    1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 2000,       //single_op state
    -1, -1, -1, -1, -1, -1, -1, 5, 6, 7, 2000,                              //double_op state
    1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 2000,       //< state
    1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 2000,       //= state
    1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 2000        //& state
    };

    //keyboard input
    if(argc == 1) {
        cout << "Enter String: " << endl;
        while(getline(cin, line_string, '\t')) {
            for(char c: line_string) {
                    str.push_back(c);
                }
        }

        //calls testScan
        testScan(fsa_table, str);

    }
    //file input
    else if (argc == 2) {
        
        ifstream myfile;
        myfile.open(argv[1]);

        if(myfile.is_open()) {
            while(getline(myfile, line_string, '\t')) {
                for(char c: line_string) {
                    str.push_back(c);
                }
            }
            
            myfile.close();
        }

        //calls testScan
        testScan(fsa_table, str);
        
    }
    //command line error
    else {
        //error
        printf("Command line error");
        exit(-1);
    }
}