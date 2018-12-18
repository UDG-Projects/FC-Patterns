#include <iostream>
#include "Matrix.h"
#include <fstream>
#include <vector>
#include "DFA.h"
#include "PDA.h"
#include "Utils.h"
using namespace std;


int main()
{
    //TODO: GET FILENAME FROM CONSOLE INPUT OR ARGUMENTS

    string fileName="data.txt";
    string pattern1D = Utils::readPatternFromFile(fileName, Utils::L2_PATTERN_DELIMITER, Utils::L_PATTERN_DELIMITER);

    vector<string> splittedMatrix = Utils::split(pattern1D, Utils::L2_PATTERN_DELIMITER);
    if(splittedMatrix.size()==2){
        Matrix matrixA = Matrix(splittedMatrix[0], Utils::L_PATTERN_DELIMITER);
        Matrix matrixB = Matrix(splittedMatrix[1], Utils::L_PATTERN_DELIMITER);


        //ALL AUTOMATAS MUST EVAL MINIMAL REPRESENTATION OF THE PATTERNS
        matrixA.minimize();
        matrixB.minimize();

        string firstPattern1D = matrixA.toString();
        string secondPattern1D = matrixB.toString();

        DFA dfa;

        int firstPatternDfaResult = dfa.eval(firstPattern1D)? 1 : -1;
        dfa.init();
        int secondPatternDfaResult = dfa.eval(secondPattern1D)? 1 : -1;

        cout << "DFA: " << firstPatternDfaResult << ", " << secondPatternDfaResult << endl;

        PDA pda;
        int firstPatternPdaResult = pda.eval(firstPattern1D)? 1 : -1;
        int secondPatternPdaResult = pda.eval(secondPattern1D)? 1 : -1;

        cout << "PDA: " << firstPatternPdaResult << ", " << secondPatternPdaResult << endl;

        int entrada = 0;

        int ticks = 0;
        Matrix estabilizedMatrix;
        while(!matrixB.equals(matrixA)  &&  !matrixA.equals(estabilizedMatrix)){
            estabilizedMatrix = matrixA;
            matrixA.performTick();
            matrixA.show();
            cout << endl;
            ticks++;
        }


        cout << "Mostrem MATRIX A : " << endl;
        matrixA.show();

        cout << "Mostrem MATRIX B : " << endl;
        matrixB.show();


        int patternTmResult = matrixB.equals(matrixA)? ticks : -1;
        cout << "T = " << ticks << endl;
        cout << "TM: " << patternTmResult << endl;

    }

}

       /** DFA WORKS!!! **/
//    DFA automata = DFA();
//    cout << automata.eval("++++-+-+-+-++++") << endl;

    /** PDA WORKS!!! **/
    /*
    PDA automata = PDA();

    for(int i = 0; i< splittedMatrix.size(); i++){
        cout << automata.eval(splittedMatrix[i]) << endl;
    }*/

    /** TURING SHOW WORKS!! (CAN BE LOOP) **/
    /*
    string patterns;
    patterns = Utils::readPatternFromFile("data.txt");
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
    }

    if(splittedMatrix.size()==2){
        Matrix matrixA = Matrix(splittedMatrix[0], 'i');
        Matrix matrixB = Matrix(splittedMatrix[1], 'i');
        matrixA.minimize();
        matrixB.minimize();
        matrixA.show();
        cout<<endl;
       //  matrixB.show();

        int ticks=0;
        Matrix estabilizedMatrix;
        while(!matrixB.equals(matrixA)  &&  !matrixA.equals(estabilizedMatrix)){
            estabilizedMatrix = matrixA;
            matrixA.performTick();
            ticks++;

            cout << ticks << endl;
            matrixA.show();

        }

        if (matrixB.equals(matrixA)){
            cout << ticks << endl;
        }
        else
            cout << -1 << endl;
    }

    */

