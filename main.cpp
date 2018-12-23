#include <iostream>
#include "MatrixPattern.h"
#include <fstream>
#include <vector>
#include <cstring>
#include "DFA.h"
#include "PDA.h"
#include "Utils.h"
#include "TM.h"

using namespace std;


int main(int argc, char *argv[])
{

    bool debug = true; //= argc > 1 && strcmp(argv[1], "-d") == 0;

    cout << debug;

    string fileName = "";
    cout << "Set file to eval : ";
    cin >> fileName;

    //string fileName="data.txt";
    string pattern1D = Utils::readPatternFromFile(fileName, Utils::L2_PATTERN_DELIMITER, Utils::L_PATTERN_DELIMITER);

    vector<string> splittedMatrix = Utils::split(pattern1D, Utils::L2_PATTERN_DELIMITER);
    if(splittedMatrix.size()==2){
        MatrixPattern matrixA = MatrixPattern(splittedMatrix[0], Utils::L_PATTERN_DELIMITER);
        MatrixPattern matrixB = MatrixPattern(splittedMatrix[1], Utils::L_PATTERN_DELIMITER);

        //DFA and PDA AUTOMATAS MUST EVAL MINIMAL REPRESENTATION OF THE PATTERNS
        matrixA.minimize();
        matrixB.minimize();

        string firstPattern1D = matrixA.toString();
        string secondPattern1D = matrixB.toString();

        string globalResult = "(";

        // Create DFA automata
        DFA dfa;
        string firstPatternDfaResult = dfa.eval(firstPattern1D)? "+1" : "-1";
        dfa.init();
        string secondPatternDfaResult = dfa.eval(secondPattern1D)? "+1" : "-1";
        globalResult += "(" + firstPatternDfaResult + "," + secondPatternDfaResult + ")";


        // Create PDA automata
        PDA pda;
        string firstPatternPdaResult = pda.eval(firstPattern1D)? "+1" : "-1";
        pda.init();
        string secondPatternPdaResult = pda.eval(secondPattern1D)? "+1" : "-1";
        globalResult += ",";
        globalResult += "(" +  firstPatternPdaResult + "," +  secondPatternPdaResult + ")";


        // Create Turing Machine
        TM tm(debug);
        // To be more exats on the TM implementation we pass all the input to the turing machine.
        int ticks = tm.eval(pattern1D);
        globalResult += "," + to_string(ticks);
        globalResult += ")";

        cout << globalResult << endl;

    }

}
