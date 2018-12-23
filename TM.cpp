//
// Created by marc on 23/12/18.
//


#include "TM.h"


TM::TM(bool debug){
    _debug = debug;
    if(debug) {
        _logFile;
        cout << "Enter a log file please : ";
        cin >> _logFile;
        std::ifstream ifile(_logFile);
        if((bool)ifile){
            remove(_logFile.c_str());
        }
    }
}

int TM::eval(string patterns) {

    vector<string> splittedMatrix = Utils::split(patterns, Utils::L2_PATTERN_DELIMITER);
    _matrixA = MatrixPattern(splittedMatrix[0], Utils::L_PATTERN_DELIMITER);
    _matrixB = MatrixPattern(splittedMatrix[1], Utils::L_PATTERN_DELIMITER);

    int ticks = 0;
    MatrixPattern estabilizedMatrix;
    MatrixPattern window3OscilationMatrix;

    /** For debug purposes **/
    ofstream stream;
    clock_t tfirst = clock();
    clock_t ti = tfirst;
    clock_t tf;
    if(_debug){
        stream.open(_logFile);
        stream << "TI;TF;Tick" << endl;
    }

    while(!_matrixB.equals(_matrixA)  &&  !_matrixA.equals(estabilizedMatrix) && !_matrixA.equals(window3OscilationMatrix)){
        window3OscilationMatrix = estabilizedMatrix;
        estabilizedMatrix = _matrixA;

        _matrixA.performTick();

        if(_debug){ /** For debug purposes **/
            _matrixA.show();
            cout << "TICK = " << ticks << endl;
            cout << endl;

            tf=clock();
            stream << ti - tfirst << ";" << tf - tfirst<< ";" << ticks << endl;
            ti = tf;
        }
        ticks++;
    }
    if(_debug){ /** For debug purposes **/
        stream.close();
    }

    return _matrixB.equals(_matrixA) ? ticks : -1;
}