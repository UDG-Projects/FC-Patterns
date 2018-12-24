#include <iostream>
#include <vector>
using namespace std;
#include "MatrixPattern.h"

MatrixPattern::MatrixPattern(){
    _delimiter=' ';
    _matrix= vector<vector<char>>(0);
}

MatrixPattern::MatrixPattern(string patternAsString, char delimiter)
{
    _delimiter = delimiter;
    createFromPattern(patternAsString);
}

MatrixPattern::MatrixPattern(int rows, int columns, char delimiter, int percentage){
    _delimiter = delimiter;
    _matrix = vector<vector<char>>(0);
    for(int row = 0; row < rows; row++){
        _matrix.push_back(vector<char>(columns));
        for(int column = 0; column < columns; column++){
            rand() % 100 < percentage ? _matrix[row][column] = '+' : _matrix[row][column] = '-';
        }
    }
}


void MatrixPattern::transpose() {

    vector<vector<char>> transposed = vector<vector<char>>(cols());
    for(int col = 0; col < cols(); col++){
        transposed[col] = vector<char>(rows());
        for(int row = 0; row < rows(); row++){
            transposed[col][row] = _matrix[row][col];
        }
    }

    _matrix=transposed;
}

void MatrixPattern::createFromPattern(string patternAsString){
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

void MatrixPattern::minimize() {
    minimizeByRows();
    transpose();
    minimizeByRows();
    transpose();
}

void MatrixPattern::minimizeByRows(){

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

int MatrixPattern::rows(){
    return _matrix.size();
}

int MatrixPattern::cols(){
    if(_matrix.size() == 0){
        return 0;
    }
    else{
        return _matrix[0].size();
    }
}

void MatrixPattern::show() {

    for(int row = 0; row < _matrix.size(); row++){
        for(int col = 0; col < _matrix[row].size(); col++){
            cout << _matrix[row][col];
        }
        cout << endl;
    }
}

void MatrixPattern::performTick(){
    vector<vector<char>> wrapped = vector<vector<char>>(rows()+2);

    for(int row = 0; row< rows()+2; row++){
        wrapped[row] = vector<char>(cols()+2);
        for(int col = 0;col<cols()+2; col++){
            wrapped[row][col]=newCellValue(row,col);
        }
    }
    _matrix=wrapped;
    minimize();
}

string MatrixPattern::toString(){
    string pattern="";
    for(int row=0; row<rows();row++){
        for(int col = 0; col < cols();col++){
            pattern+=_matrix[row][col];
        }
        pattern+=_delimiter;
    }

     return pattern.substr(0, pattern.size() - 1);

}

char MatrixPattern::newCellValue(int row, int column){
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

bool MatrixPattern::equals(MatrixPattern matrixToEval){
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
