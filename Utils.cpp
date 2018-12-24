//
// Created by marc on 06/12/18.
//
#include <fstream>
#include <iostream>

#include "Utils.h"

const char Utils::L2_PATTERN_DELIMITER='j';
const char Utils::L_PATTERN_DELIMITER='i';

vector<string> Utils::split(string patternToSplit, char delimiter) {
    vector <string> fields;
    string bread="";
    for(int i =0; i<patternToSplit.size(); i++){
        if(patternToSplit[i]!=delimiter){
            bread+=patternToSplit[i];
        }else{
            fields.push_back(bread);
            bread="";
        }
    }
    fields.push_back(bread);
    return fields;
}


string Utils::readPatternFromFile(string nFile, char l2Delimiter, char lDelimiter){
    string bread = "";
    string matrix1D = "";
    ifstream fileIn(nFile);
    if (fileIn.is_open()) {
        while(! fileIn.eof()){
            getline (fileIn,bread);
            matrix1D+=bread; // versio tota la matriu
            if(bread == "\0"){
                matrix1D = matrix1D.substr(0, matrix1D.size() -1);
                matrix1D += l2Delimiter;
            }
            else {
                matrix1D+=lDelimiter;
            }
        }
        fileIn.close();
        matrix1D = matrix1D.substr(0, matrix1D.size() -1);
    }

    return matrix1D;
}


void Utils::removeExistingFile(string fileName) {
    std::ifstream ifile(fileName);
    if((bool)ifile){
        remove(fileName.c_str());
    }
}

void Utils::printOnFile(string filename, string toPrint) {
    ofstream stream;
    // Append mode
    stream.open(filename, ios_base::app);
    stream << toPrint << endl;
    stream.close();
    cout << "## Printed : " << toPrint << endl;
}