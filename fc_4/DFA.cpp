//
// Created by Marc Sánchez on 2018-12-05.
//

#include "DFA.h"

DFA::DFA(){
    _actualState = q0;
}

void DFA::init(){
    _actualState = q0;
}

bool DFA::eval(string word){

    for(int inputNumber = 0; inputNumber < word.size(); inputNumber++){
        char input = word[inputNumber];
        if(input == 'i'){
            if(_actualState == q17)
                _actualState = q17;
            else
                _actualState = q0;
        }
        else {
            if(_actualState == q0){
                if(input == '+'){
                    _actualState = q1;
                }
                else{
                    _actualState = q0;
                }
            }
            else if(_actualState == q1){
                if(input == '+'){
                    _actualState = q2;
                }
                else{
                    _actualState = q0;
                }
            }
            else if(_actualState == q2){
                if(input == '+'){
                    _actualState = q3;
                }
                else{
                    _actualState = q0;
                }
            }
            else if(_actualState == q3){
                if(input == '+'){
                    _actualState = q4;
                }
                else{
                    _actualState = q0;
                }
            }
            else if(_actualState == q4){
                if(input == '+'){
                    _actualState = q4;
                }
                else{
                    _actualState = q5;
                }
            }
            else if(_actualState == q5){
                if(input == '+'){
                    _actualState = q6;
                }
                else{
                    _actualState = q5;
                }
            }
            else if(_actualState == q6){
                if(input == '+'){
                    _actualState = q4;
                }
                else{
                    _actualState = q7;
                }
            }
            else if(_actualState == q7){
                if(input == '+'){
                    _actualState = q9;
                }
                else{
                    _actualState = q7;
                }
            }
            else if(_actualState == q8){
                if(input == '+'){
                    _actualState = q8;
                }
                else{
                    _actualState = q7;
                }
            }
            else if(_actualState == q9){
                if(input == '+'){
                    _actualState = q8;
                }
                else{
                    _actualState = q10;
                }
            }
            else if(_actualState == q10){
                if(input == '+'){
                    _actualState = q12;
                }
                else{
                    _actualState = q10;
                }
            }
            else if(_actualState == q11){
                if(input == '+'){
                    _actualState = q11;
                }
                else{
                    _actualState = q10;
                }
            }
            else if(_actualState == q12){
                if(input == '+'){
                    _actualState = q11;
                }
                else{
                    _actualState = q13;
                }
            }
            else if(_actualState == q13){
                if(input == '+'){
                    _actualState = q14;
                }
                else{
                    _actualState = q13;
                }
            }
            else if(_actualState == q14){
                if(input == '+'){
                    _actualState = q15;
                }
                else{
                    _actualState = q13;
                }
            }
            else if(_actualState == q15){
                if(input == '+'){
                    _actualState = q16;
                }
                else{
                    _actualState = q13;
                }
            }
            else if(_actualState == q16){
                if(input == '+'){
                    _actualState = q17;
                }
                else{
                    _actualState = q13;
                }
            }
            else if(_actualState == q17){
                _actualState = q17;
            }
            else {
                // do nothing..
            }

        }
    }

    return _actualState == q17;

}
