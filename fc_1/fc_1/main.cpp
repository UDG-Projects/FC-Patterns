#include <iostream>
#include "Utils.h"
#include "DFA.h"

using namespace std;

int main()
{

    string fileName = "";
    cout << "Set file to eval which contains a L word : ";
    cin >> fileName;
    string pattern1D = Utils::readPatternFromFile(fileName, Utils::L2_PATTERN_DELIMITER, Utils::L_PATTERN_DELIMITER);

    DFA dfa;
    dfa.init();
    string dfaResult = dfa.eval(pattern1D)? "+1" : "-1";

    cout << endl << dfaResult << endl;
}

