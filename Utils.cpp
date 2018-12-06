//
// Created by marc on 06/12/18.
//

#include "Utils.h"

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
