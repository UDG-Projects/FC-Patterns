//
// Created by marc on 06/12/18.
//

#ifndef PRACTICAFINAL_UTILS_H
#define PRACTICAFINAL_UTILS_H
using namespace std;

#include <string>
#include <vector>

class Utils {

public:

    static const char L2_PATTERN_DELIMITER;
    static const char L_PATTERN_DELIMITER;

    /**
     * Trnasform a string into a vector splitted with the char delimiter
     * @param patternToSplit string to be divided.
     * @param delimiter character used to divide string
     * @return a vector with all parts of the divided string ordered by aparition.
     */
    static vector<string> split(string patternToSplit, char delimiter);

    /**
     *
     * @param nFile
     * @param l2Delimiter
     * @param lDelimiter
     */
    static string readPatternFromFile(string nFile, char l2Delimiter, char lDelimiter);
private:


};


#endif //PRACTICAFINAL_UTILS_H
