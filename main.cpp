#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <vector>
#include "DFA.h"
#include "PDA.h"
#include "Utils.h"
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
    // cout << matrix1D << endl;
    return matrix1D;
}



int main()
{
    /** DFA WORKS!!! **/
//    DFA automata = DFA();
//    cout << automata.eval("++++-+-+-+-++++") << endl;

    /** PDA WORKS!!! **/
    /*
    PDA automata = PDA();

    for(int i = 0; i< splittedMatrix.size(); i++){
        cout << automata.eval(splittedMatrix[i]) << endl;
    }*/


    string patterns;
    patterns = readPatternFromFile("data.txt");
    vector<string> splittedMatrix = Utils::split(patterns, 'j');

    /*for(int i = 0; i< splittedMatrix.size(); i++){
        Matrix matrix = Matrix(splittedMatrix[i], 'i');
        matrix.minimize();
        matrix.show();

        cout << endl;
        cout << endl;

        matrix.performTick();
        matrix.show();
        cout << endl;
        matrix.performTick();
        matrix.show();

        cout << endl;
    }*/

    if(splittedMatrix.size()==2){
        Matrix matrixA = Matrix(splittedMatrix[0], 'i');
        Matrix matrixB = Matrix(splittedMatrix[1], 'i');
        matrixA.minimize();
        matrixB.minimize();
        matrixA.show();
        cout<<endl;
      //  matrixB.show();

        int ticks=0;
        while(!matrixB.equals(matrixA) && ticks<4){
            matrixA.performTick();
            ticks++;
            matrixA.show();
            cout << ticks << endl;

        }
        //matrixA.show();

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