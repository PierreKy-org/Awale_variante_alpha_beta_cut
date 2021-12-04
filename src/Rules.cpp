#include <iostream>
#include <cstdlib>  
#include <sstream>
#include <string>
#include "Move.cpp"
#include "Board.cpp"
using namespace std;

/*Renvois un objet Move, si le move commence à -1 il est cassé"*/
//Default input permet de tester et aussi de jouer sans attendre les inputs du joueur
Move parse_a_move(string defaultInput=""){
    //TODO ajouter le numéro du tour ou le joueur qui joue le coup
    string input;

    if(defaultInput == ""){
        cout << "Enter a move";
        cin >> input; 
    } else {
        input = defaultInput;
    }

    char color = input[input.length() -1];
    input.erase(input.length() -1, 1);
    int start = stoi(input);

    Move move = Move(start, color);
    if ((color != 'B') && (color != 'R')){
        //Move errone
        move.starting_hole = -1;
        move.color = '0';
    }
    return move;
}

void is_a_move_legit(Board board, Move move){
    //effectue les checks 
    //renvois vrai ou faux
}

void execute_a_move(Board board, Move move){
    //En partant du principe qu'un move est valide
    //on l'applique au board
}










