#include <iostream>
#include <cstdlib>  
#include <sstream>
#include <string>
#include "WinningRules.cpp"
using namespace std;

/**
 * l'index correspond à l'index de la case
 * sur laquelle on a terminé le Move.
 * 
 * joueur permet d'indiquer quel est le joueur qui a effectué
 * le coup (et qui récuperera les grains)
 * 
 * Fonction : 
 *  1)    Regarde chaque trou à partir du start_index (dans l'ordre inverse)
 *  2)    Pour chaque coup regarde s'il est vide :
 *  2.1)      S'il l'est : le joueur joueur gagne les graines et on revient à 2
 *  2.2)      Sinon on arrête la fonction
 */ 
Board capture(Board board, int start_index, int joueur){
    //printf("called on %d \n", start_index);
    int n;
    for (int i=0; i < 16; i++){
        n = start_index - i;

        //ce if est moche mais c'est un modulo python à la main
        if (n < 0){
            n = 15;
        }
        if (board.cases[n].isTakeable()){
            if (joueur == 0){
                board.gainJ1 = board.gainJ1 + board.cases[n].empty_all();
            }else{
                board.gainJ2 = board.gainJ2 + board.cases[n].empty_all();
            }
        }else{
            return board;
        }
    }
    //Normalement on rentre jamais là dedans
    return board;
}