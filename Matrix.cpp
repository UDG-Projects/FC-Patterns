#include <iostream>
#include <vector>
using namespace std;
#include "Matrix.h"

Matrix::Matrix(string patternAsString, char delimiter)
{
    _delimiter = delimiter;
    createFromPattern(patternAsString);
}

void Matrix::transpose() {

    vector<vector<char>> transposed = vector<vector<char>>(cols());
    for(int col = 0; col < cols(); col++){
        transposed[col] = vector<char>(rows());
        for(int row = 0; row < rows(); row++){
            transposed[col][row] = _matrix[row][col];
        }
    }

    _matrix=transposed;
}

void Matrix::createFromPattern(string patternAsString){
    vector<string> dividedPattern = Utils::split(patternAsString, _delimiter);
    _matrix = vector<vector<char>>();

    for(int row = 0; row < dividedPattern.size(); row++){
        string part = dividedPattern[row];
        _matrix.push_back(vector<char>(part.size()));
        for(int col = 0; col < part.size(); col++){
            _matrix[row][col] = part[col];
        }
    }
}

void Matrix::minimize() {
    minimizeByRows();
    transpose();
    minimizeByRows();
    transpose();

}

void Matrix::minimizeByRows(){

    bool firstPlusOnPattern = false;
    bool plusOnBread = false;

    string tmpPattern = "";
    string validPattern = "";

    for(int row = 0; row < rows(); row++){
        for(int col = 0; col < cols(); col++){
            char symbol = _matrix[row][col];
            tmpPattern += symbol;
            firstPlusOnPattern = symbol == '+' || firstPlusOnPattern;
            plusOnBread = symbol == '+' || plusOnBread;
        }
        // We add the sepparator
        tmpPattern += 'i';

        // we decide what we have to do with the string.
        if(firstPlusOnPattern && plusOnBread){
            validPattern += tmpPattern;
        }

        if(plusOnBread || !firstPlusOnPattern){
            tmpPattern = "";
        }
        plusOnBread = false;
    }

    validPattern = validPattern.substr(0, validPattern.size() - 1);

    createFromPattern(validPattern);
}

int Matrix::rows(){
    return _matrix.size();
}

int Matrix::cols(){
    if(_matrix.size() == 0){
        return 0;
    }
    else{
        return _matrix[0].size();
    }
}

void Matrix::show() {

    for(int row = 0; row < _matrix.size(); row++){
        for(int col = 0; col < _matrix[row].size(); col++){
            cout << _matrix[row][col];
        }
        cout << endl;
    }
}

void Matrix::performTick(){
    vector<vector<char>> wrapped = vector<vector<char>>(rows()+2);

    for(int row = 0; row< rows()+2; row++){
        wrapped[row] = vector<char>(cols()+2);
        for(int col = 0;col<cols()+2; col++){
            wrapped[row][col]=newCellValue(wrapped, rows()+2,cols()+2,row,col);
        }
    }
    _matrix=wrapped;
    minimize();
}

char Matrix::newCellValue(vector<vector<char>> wrappedMatrix, int wrappedRows,int wrappedColumns, int row, int column){
    int actives = 0;
    for(int subRow = row-1; subRow<=row+1;subRow++){
        for(int subCol = column-1;subCol<=column+1;subCol++){
            if((subRow -1 >= 0 && subRow - 1 < rows() && subCol - 1 >= 0 && subCol - 1 < cols()) && !(subRow == row && subCol == column) && _matrix[subRow - 1][subCol - 1]=='+')
                actives++;
        }
    }
    if((row > 0 && row <= rows() && column > 0 && column <= cols()) && ((_matrix[row - 1][column - 1]=='+' && (actives ==2 || actives ==3)) || (_matrix[row - 1][column - 1]!='+' && actives ==3)))
        return '+';
    else if(!(row > 0 && row <= rows() && column > 0 && column <= cols()) && actives ==3)
        return '+';
    else
        return '-';

}

bool Matrix::equals(Matrix matrixToEval){
    bool equals = true;
    if(rows()!=matrixToEval.rows() || cols()!=matrixToEval.cols())
        return false;
    int row = 0;
    while(row<rows() && equals){
        int col = 0;
        while(col<cols() && equals) {
            equals = _matrix[row][col] == matrixToEval._matrix[row][col];
            col++;
        }
        row++;
    }

    return equals;
}
