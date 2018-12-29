#include <iostream>
#include "TM.h"
#include "Utils.h"


using namespace std;

int main()
{
    string fileName = "";
    cout << "Set file to eval which contains a L² word : ";
    cin >> fileName;

    string pattern1D = Utils::readPatternFromFile(fileName, Utils::L2_PATTERN_DELIMITER, Utils::L_PATTERN_DELIMITER);

    // Create Turing Machine
    TM tm(false);
    // To be more exats on the TM implementation we pass all the input to the turing machine.
    int ticks = tm.eval(pattern1D);

    cout << ticks << endl;
}
