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


//TODO: extreure entrada a part
/**
 * PRE:
 * POST:
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
 * PRE:
 * POST:
 */
void generationMode(){

    srand(time(NULL));
    int iterations;
    int percentage;
    int columns;
    int rows;
    int factor;
    string logFile;

    cout << "* Please enter the following paramters : " << endl;
    cout << "* Number of iterations :> ";
    cin >> iterations;
    cout << "* + symbol percentage of apparitions (0 -100)> ";
    cin >> percentage;
    cout << "* Number of rows :> ";
    cin >> rows;
    cout << "* Number of columns :> ";
    cin >> columns;
    cout << "* Growing factor :> ";
    cin >> factor;
    cout << "* statistics file name printed in csv?> ";
    cin >> logFile;


    /** For debug purposes **/
    ofstream stream;
    clock_t tfirst = clock();
    clock_t ti = tfirst;
    clock_t tf;
    stream.open(logFile);
    stream << "Iteration;Rows;Columns;TI;TF;Result" << endl;

    // Delete logfile if exists
    std::ifstream ifile(logFile);
    if((bool)ifile){
        remove(logFile.c_str());
    }

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
        int tick = tm.eval(word);

        // Getting time and filling statistics

        tf=clock();
        string result = to_string(rows) +";"+ to_string(columns) + ";"+ to_string(ti - tfirst) +";"+ to_string(tf - tfirst) +";"+ to_string(tick);
        stream << result << endl;
        cout << result << endl;

        // Init variables
        ti = tf;
        rows *= factor;
        columns *= factor;
        i++;
    }
    // Close log file
    stream.close();

}

/**
 * PRE: Execute program in debug mode.
 * POST: Patterns will be generated or entered from file.
 * The generation will be random taking + 75% of possibilities to appear and - 25%.
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


int main(int argc, char *argv[])
{

    bool debug = true; //= argc > 1 && strcmp(argv[1], "-d") == 0;

    if(debug){
        godMode();
    }
    else{
        normalMode();
    }

    return 0;

}
