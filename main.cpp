#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <vector>
#include "DFA.h"
#include "PDA.h"
using namespace std;


string readPatternFromFile(string nFile){
    string bread = "";
    string matrix1D = "";
    ifstream fileIn(nFile);
    if (fileIn.is_open()) {
        while(! fileIn.eof()){
            getline (fileIn,bread);
            matrix1D+=bread; // versio tota la matriu
            if(bread == "\0"){
                matrix1D = matrix1D.substr(0, matrix1D.size() -1);
                matrix1D += "j";
            }
            else {
                matrix1D+="i";
            }
        }
        fileIn.close();
        matrix1D = matrix1D.substr(0, matrix1D.size() -1);
    }
     cout << matrix1D << endl;
    return matrix1D;
}

vector<string> split(string matrixL2, char delimiter){
    vector <string> fields;
    string bread="";
    for(int i =0; i<matrixL2.size(); i++){
        if(matrixL2[i]!=delimiter){
            bread+=matrixL2[i];
        }else{
            fields.push_back(bread);
            bread="";
        }
    }
    fields.push_back(bread);
    return fields;
}


int main()
{
    /** DFA WORKS!!! **/
//    DFA automata = DFA();
//    cout << automata.eval("++++-+-+-+-++++") << endl;


    string patterns;
    Matrix a;
    patterns = readPatternFromFile("data.txt");
    vector<string> splittedMatrix = split(patterns, 'j');

    PDA automata = PDA();

    for(int i = 0; i< splittedMatrix.size(); i++){
        cout << automata.eval(splittedMatrix[i]) << endl;
    }
}

    /*
    for(int field = 0; field < splittedMatrix.size(); field ++){
        cout << splittedMatrix[field] <<  endl;
    }
    cout << "sdfgasfdgasd" <<  endl;

    vector<vector<string>> allMatrix;
    for(int field = 0; field < splittedMatrix.size(); field ++){
        allMatrix.push_back(split(splittedMatrix[field], 'i'));
    }
    cout << allMatrix.size() << endl;
    for(int i = 0; i< allMatrix.size(); i++){
        cout << "Matriu num " << i << endl;
        for(int j = 0; j < allMatrix[i].size(); j++){
            cout << allMatrix[i][j] << endl;
        }
    }
    cout << endl;

}
*/