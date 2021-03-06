//
// Created by marc on 06/12/18.
//

#ifndef PRACTICAFINAL_PDA_H
#define PRACTICAFINAL_PDA_H

using namespace std;

#include <string>
#include <stack>
#include "Alphabet.h"

class PDA {

public:

    /**
     * Constructor.
     */
    PDA();

    /**
     * Evals word over PDA automaton.
     * @return True if the word is accepted by the automaton, false anyway.
     */
    bool eval(string word);

    /**
     * Reset all values for PDA Automata (starting state)
     */
    void init();

private:

    /** Declaring all states as a private constants **/
    const string q0 = "";
    const string q1 = "buida";
    const string q2 = "trec +";
    const string q3 = "top +";
    const string q4 = "on soc";
    const string q5 = "top -";
    const string q6 = "push -";


    /** Store the actual state */
    string _actualState;

    /** Stack used by pda automaton */
    stack<Alphabet::Delta> _stack;

};


#endif //PRACTICAFINAL_PDA_H
