#include <iostream>
#include <cstdlib>  
#include <sstream>
#include <string>
#include "Move.cpp"
#include "Board.cpp"
using namespace std;

/**
 * l'index correspond à l'index de la case
 * sur laquelle on a terminé le Move.
 * 
 * joueur permet d'indiquer quel est le joueur qui a effectué
 * le coup (et qui récuperera les grains)
 */ 
void capture(Board board, int index, int joueur){
    for (int i=0; i < 16; i++){
        index = (index - i)%16;
        if (board.cases[index].isTakeable()){
            if (joueur == 0){
                board.gainJ1 = board.gainJ1 + board.cases[index].empty_all();
                printf("le joueur01 a gagné %d\n", board.gainJ1 );
            }else{
                board.gainJ2 = board.gainJ2 + board.cases[index].empty_all();
                printf("le joueur02 a gagné %d\n", board.gainJ2 );
            }
        }else{
            break;
        }
    }
}