//
// Created by marc on 06/12/18.
//

#include "PDA.h"
#include "Alphabet.h"

PDA::PDA(){
    _actualState = q0;
}

bool PDA::eval(string word) {

    // Going from q0 to q1 and adding the delimiter to the stack.
    _actualState = q1;
    _stack.push(Alphabet::Delta::DOLLAR);

    int symbolNumber = 0;
    while(symbolNumber < word.size()) {

        char symbol = word[symbolNumber];
        if(_actualState == q1){
            if(symbol == Alphabet::Sigma::ENTER){
                // do nothing
            }
            else if(symbol == Alphabet::Sigma::PLUS_S){
                _actualState = q3;
                _stack.push(Alphabet::Delta::PLUS_D);
                if(_stack.top() == Alphabet::Delta::PLUS_D && symbolNumber == word.size() -1) { // Si estic l'últim symbol del mot...
                    _actualState = q7;
                    while(_stack.top() == Alphabet::Delta::PLUS_D){
                        _stack.pop();
                    }
                    return _stack.top() == Alphabet::Delta::DOLLAR;
                }
            }
            else {
                _actualState = q6;
                _stack.push(Alphabet::Delta::MINUS_D);
                _actualState = q5;
                _stack.push(Alphabet::Delta::MINUS_D);
            }
        }
        else if(_actualState == q2){
            // Epsilon transitions
        }
        else if(_actualState == q3){
            if(symbol == Alphabet::Sigma::ENTER){
                if(symbolNumber == word.size() -1) { // Si estic l'últim symbol del mot...
                    _actualState = q7;
                    while(_stack.top() == Alphabet::Delta::PLUS_D){
                        _stack.pop();
                    }
                    return _stack.top() == Alphabet::Delta::DOLLAR;
                }
            }
            else if(symbol == Alphabet::Sigma::PLUS_S){
                _stack.push(Alphabet::Delta::PLUS_D);
                 if(symbolNumber == word.size() -1) { // Si estic l'últim symbol del mot...
                    _actualState = q7;
                    while(_stack.top() == Alphabet::Delta::PLUS_D){
                        _stack.pop();
                    }
                    return _stack.top() == Alphabet::Delta::DOLLAR;
                }
            }
            else {
                _actualState = q2;
                _stack.pop();
                if(_stack.top() == Alphabet::Delta::DOLLAR){
                    _actualState = q4;
                    _stack.push(Alphabet::Delta::MINUS_D);
                    _actualState = q5;
                }
                else{
                    _stack.pop();
                    if(_stack.top() == Alphabet::Delta::DOLLAR){
                        _actualState = q1;
                    }
                    else{
                        _actualState = q3;
                        if(symbolNumber == word.size() -1) { // Si estic l'últim symbol del mot...
                            _actualState = q7;
                            while(_stack.top() == Alphabet::Delta::PLUS_D){
                                _stack.pop();
                            }
                            return _stack.top() == Alphabet::Delta::DOLLAR;
                        }
                    }
                }
            }

        }
        else if(_actualState == q4){
            // Epsilon transitions
        }
        else if(_actualState == q5){
            if(symbol == Alphabet::Sigma::ENTER){
                // do NOTHING
            }
            else if(symbol == Alphabet::Sigma::PLUS_S){
                _stack.pop();
                if(_stack.top() == Alphabet::Delta::MINUS_D){
                    // DO nothing
                }
                else if (_stack.top() == Alphabet::Delta::PLUS_D){
                    _actualState = q3;
                    if(symbolNumber == word.size() -1) { // Si estic l'últim symbol del mot...
                        _actualState = q7;
                    }
                }
                else{
                    _actualState = q1;
                }
            }
            else {
                _stack.push(Alphabet::Delta::MINUS_D);
                _actualState = q6;
                _stack.push(Alphabet::Delta::MINUS_D);
                _actualState = q5;
            }
        }
        else if(_actualState == q6){
            // Epsilon transitions
        }
        else if(_actualState == q7){
            while(_stack.top() == Alphabet::Delta::PLUS_D){
                _stack.pop();
            }
            return _stack.top() == Alphabet::Delta::DOLLAR;
        }
        else {
            // Do nothing...
        }
        symbolNumber++;
    }
    return false;
}
