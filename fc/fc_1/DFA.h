//
// Created by Marc Sánchez on 2018-12-05.
//
#ifndef PRACTICAFINAL_DFA_H
#define PRACTICAFINAL_DFA_H

using namespace std;

#include <set>
#include <iostream>
#include <string>

class DFA {

public:

    /**
     * Constructor
     */
    DFA();

    /**
     * This function evals a string and returns if the word if accepted by this automata.
     * @param word the word formed with Sigma symbols to be evaluated
     * @return True if the word is accepted by our automata, false anywhere
     */
    bool eval(string word);

    /**
     * Resets all values for DFA automata (starting state)
     */
    void init();

private:

    /** Declaring all states as a private constants **/
    const string q0 = "";
    const string q1 = "+";
    const string q2 = "++";
    const string q3 = "+++";
    const string q4 = "++++";
    const string q5 = "1-";
    const string q6 = "1-+";
    const string q7 = "1a";
    const string q8 = "2+";
    const string q9 = "2-+";
    const string q10 = "2a";
    const string q11 = "3+";
    const string q12 = "3-+";
    const string q13 = "3a";
    const string q14 = "+2";
    const string q15 = "++2";
    const string q16 = "+++2";
    const string q17 = "++++2";

    /** Attribute actual state to save where the machine is. **/
    string _actualState;

};




#endif //PRACTICAFINAL_DFA_H
