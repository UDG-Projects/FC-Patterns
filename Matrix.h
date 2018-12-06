#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

#include <iostream>
#include <vector>
#include "Utils.h"

class Matrix
{
public:
    /**
     *
     * @param patternAsString
     */
    Matrix(string patternAsString, char delimiter);

    /**
     *
     */
    void show();

    /**
     *
     */
    void minimize();

    /**
     *
     * @return
     */
    int rows();

    /**
     *
     * @return
     */
    int cols();
    /**
     *
     */
    void performTick();
    /**
     *
     * @param matrixToEval
     * @return
     */
    bool equals(Matrix matrixToEval);

private:
    /**
     * Attributes
     */
    vector<vector<char>> _matrix;
    char _delimiter;

    /**
     *
     */
    void transpose();

    /**
     *
     * @param patternAsString
     * @param delimiter
     */
    void createFromPattern(string patternAsString);

    /**
     *
     */
    void minimizeByRows();
    /**
     *
     * @param wrappedRows
     * @param wrappedColumns
     * @param row
     * @param column
     */
    char newCellValue(vector<vector<char>> wrappedMatrix,int wrappedRows,int wrappedColumns, int row, int column);

};

#endif // MATRIX_H
