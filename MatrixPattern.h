#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <iostream>
#include <vector>
#include "Utils.h"

class MatrixPattern
{
public:

    /**
     * Default Contstructor.
     */
    MatrixPattern();

    /**
     * Initializes a MatrixPattern from string
     * @param patternAsString The entire pattern to create matrix
     * @param delimiter char to delimiter the rows of pattern
     */
    MatrixPattern(string patternAsString, char delimiter);

    MatrixPattern(int rows, int columns, char delimiter, int percentage);

    /**
     * prints pattern like matrix throught cout
     */
    void show();

    /**
     * PRE: this € P_p
     * POST: this € P_0
     */
    void minimize();

    /**
     * PRE: true
     * @return number of rows of MatrixPattern
     */
    int rows();

    /**
     * PRE: True
     * @return number of columns of MatrixPattern
     */
    int cols();

    /**
     * PRE: True
     * POST: this = P^t+1
     */
    void performTick();

    /**
     * PRE: True
     * @param matrixToEval
     * @return True if matrixToEval = this, false anyway
     */
    bool equals(MatrixPattern matrixToEval);

    /**
     * PRE: True
     * @return this as P
     */
    string toString();


private:

    /**
     * Attributes
     */
    vector<vector<char>> _matrix;
    char _delimiter;

    /**
     * PRE: True
     * POST: this has been transposed
     */
    void transpose();

    /**
     * PRE: TRUE
     * @param patternAsString € P
     * @param delimiter € Sigma*
     * POST: this is created from patternAsString
     */
    void createFromPattern(string patternAsString);

    /**
     * PRE: True
     * POST: This is represented as P_0 only by rows
     */
    void minimizeByRows();

    /**
     * PRE: True
     * @param row >= 0 < rows()
     * @param column>= 0 < cols()
     * @return the new character to be evoluted in row and column for this
     */
    char newCellValue(int row, int column);

};

#endif // MATRIX_H
