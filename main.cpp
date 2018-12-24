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

/**
 * PRE: True
 * POST: Filename containing L² word asked, pattern(s) from filename will be passed to DFA, PDA and TM.
 *       Prints result for *5.4 Fusió*
 */
void normalMode(bool debug = false, bool showAll = false){

    string fileName = "";
    cout << "Set file to eval which contains a L² word : ";
    cin >> fileName;

    string pattern1D = Utils::readPatternFromFile(fileName, Utils::L2_PATTERN_DELIMITER, Utils::L_PATTERN_DELIMITER);
    vector<string> splittedMatrix = Utils::split(pattern1D, Utils::L2_PATTERN_DELIMITER);

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
    TM tm(debug, showAll);
    // To be more exats on the TM implementation we pass all the input to the turing machine.
    int ticks = tm.eval(pattern1D);
    globalResult += "," + to_string(ticks);
    globalResult += ")";

    cout << globalResult << endl;
}

/**
 * PRE: True
 * POST: Patterns will be generated and passed to TM, log File will be created.
 *       Params asked to pattern generation and factor growing.
 */
void generationMode(){

    srand(time(NULL));
    int iterations;
    int percentage;
    int columns;
    int rows;
    double factor;
    string logFile;

    cout << "* Please enter the following paramters : " << endl;
    cout << "* How much patterns will be generated?> ";
    cin >> iterations;
    cout << "* + symbol percentage of apparitions (0 -100) :> ";
    cin >> percentage;
    cout << "* Number of rows :> ";
    cin >> rows;
    cout << "* Number of columns :> ";
    cin >> columns;
    cout << "* Growing factor :> ";
    cin >> factor;
    cout << "* statistics file name printed in csv?> ";
    cin >> logFile;

    /**
     * Preparing log file in csv format!
     */
    // Delete logfile if exists
    Utils::removeExistingFile(logFile);
    // Printing variables on csv
    Utils::printOnFile(logFile, "Grow Factor;Percentage Apparitions;Expected Iterations");
    Utils::printOnFile(logFile, to_string(factor) + ";" + to_string(percentage) + ";" + to_string(iterations));
    for(int separation = 0; separation < 5; separation++){
        Utils::printOnFile(logFile, "");
    }
    // Printing header for logFile
    Utils::printOnFile(logFile, "Iteration;Rows;Columns;Clocks;Ticks");

    int i = 0;
    while(i < iterations) {



        MatrixPattern A = MatrixPattern(rows, columns, Utils::L_PATTERN_DELIMITER, percentage);
        MatrixPattern B = MatrixPattern(rows, columns, Utils::L_PATTERN_DELIMITER, percentage);
        cout << "*******************************************" << endl;
        cout << "* Pattern generated :" << endl;
        A.show();
        cout << endl;
        B.show();
        cout << endl << endl;

        // Mounting a word compressed in L²
        string word = A.toString() + Utils::L2_PATTERN_DELIMITER + B.toString();

        // Execute turing machine
        TM tm(true);

        // Getting time befor start
        clock_t ti = clock();

        int tick = tm.eval(word);

        // Getting time and filling statistics
        clock_t tf=clock();

        // Printing details on logFile
        Utils::printOnFile(logFile,to_string(rows) +";"+ to_string(columns) + ";"+ to_string(tf - ti) +";"+ to_string(tick));

        // Init variables
        rows *= factor;
        columns *= factor;
        i++;
    }
    // Close log file


}

/**
 * PRE: Execute program in debug mode.
 * POST: Patterns will be generated or entered from file.
 * The generation will be random taking variable integer from user for + symbol possibilities apparition.
 */
void godMode(){

    cout << "*********** You are in god mode ***********" << endl;
    string option = "-1";
    do{

        cout << "*******************************************" << endl;
        cout << "*  Please enter one of following numbers  *" << endl;
        cout << "*                                         *" << endl;
        cout << "* Pattern Generation -----------------> 1 *" << endl;
        cout << "* Pattern from file  -----------------> 2 *" << endl;
        cout << "* Pattern from file show all matrix --> 3 *" << endl;
        cout << "* Exit  ------------------------------> 0 *" << endl;
        cout << "*******************************************" << endl;
        cout << "> ";
        cin >> option;
        if(option == "1"){
            generationMode();
        }
        else if(option == "2"){
            normalMode(true);
        }
        else if(option=="3"){
            normalMode(true, true);
        }
        else if(option == "0") {
            cout << "* Thank you!                              *" << endl;
        }
        else{
            cout << "* Bad Option!                             *" << endl;
            cout << "* Retry!                                  *" << endl;
        }

    } while(option != "0");

}

/**
 * PRE:
 * @param argc Number of arguments for main
 * @param argv Option "-d" will enter in debug mode
 * @return 0 if all ok, if loop will stand running
 */
int main(int argc, char *argv[])
{

    bool debug = argc > 1 && strcmp(argv[1], "-d") == 0;

    if(debug){
        godMode();
    }
    else{
        normalMode();
    }

    return 0;

}
