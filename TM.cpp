//
// Created by marc on 23/12/18.
//


#include "TM.h"

TM::TM(bool debug, bool showAllMatrix){
    _debug = debug;
    _showAll = showAllMatrix;
}

int TM::eval(string patterns) {

    vector<string> splittedMatrix = Utils::split(patterns, Utils::L2_PATTERN_DELIMITER);
    _matrixA = MatrixPattern(splittedMatrix[0], Utils::L_PATTERN_DELIMITER);
    _matrixB = MatrixPattern(splittedMatrix[1], Utils::L_PATTERN_DELIMITER);

    int ticks = 0;
    MatrixPattern estabilizedMatrix;
    MatrixPattern window3OscilationMatrix;

    while(!_matrixB.equals(_matrixA)  &&  !_matrixA.equals(estabilizedMatrix) && !_matrixA.equals(window3OscilationMatrix)){
        window3OscilationMatrix = estabilizedMatrix;
        estabilizedMatrix = _matrixA;

        if(_showAll){
            _matrixA.show();
            cout << endl;
            _matrixB.show();
            cout << endl;
        }

        _matrixA.performTick();

        ticks++;
    }

    return (_matrixB.equals(_matrixA) or _debug) ? ticks : -1;
}