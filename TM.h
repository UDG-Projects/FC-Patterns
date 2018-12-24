//
// Created by marc on 23/12/18.
//

#ifndef PRACTICAFINAL_TM_H
#define PRACTICAFINAL_TM_H

using namespace std;
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include "MatrixPattern.h"

class TM {

public:


    /**
     * Connstructor for Turing Machine class.
     * @param patterns w € L²
     */
    TM(bool debug = false, bool showAllMatrix = false);


    /**
     * Executes Machine TM with input stored at creation.
     * @param debug if true prints some spects throught output.
     * @return integer representing tick for evolution from MatrixA to MatrixB, or -1 if can't be evoluted to MatrixB.
     */
    int eval(string patterns);

private:

    /** Attrinbutes **/
    MatrixPattern _matrixA;
    MatrixPattern _matrixB;
    bool _debug;
    bool _showAll;

};


#endif //PRACTICAFINAL_TM_H
