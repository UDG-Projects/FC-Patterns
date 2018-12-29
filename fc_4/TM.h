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
     * @param if true eval ever returns tick counter
     * @param showAllMatrix if true eval prints all evolutions throught stdout
     */
    TM(bool debug = false, bool showAllMatrix = false, int l3 = -1);


    /**
     * Executes Machine TM with input stored at creation.
     * @param patterns w € L²
     * @return integer representing tick for evolution from MatrixA to MatrixB, or -1 if can't be evoluted to MatrixB, else loop (nothing returned).
     */
    int eval(string patterns);

private:

    /** Attrinbutes **/
    MatrixPattern _matrixA;
    MatrixPattern _matrixB;
    bool _debug;
    bool _showAll;
    // When l3 takes a value upper than -1 then will perform l3 evolutions.
    int _l3; // Attribute to control L³ language

};


#endif //PRACTICAFINAL_TM_H
