#include <iostream>
#include <cstdlib>  
#include <sstream>
#include <string>
#include "SowingRules.cpp"
using namespace std;



// FAIRE ATTENTION A LA VERIF de quand il reste moins de 8 graines :
//(on ne prend pas en compte le tableau juste les gains des joueurs)
/**
 * Détermine si la partie peut continuer
 * Ou si on a atteint un cas d'arrêt
 */ 
bool is_it_the_end_of_the_game(Board board){


    //Un joueur a la majorité des graines
    if (board.gainJ1 > 32 || board.gainJ2 > 32){
        return true;
    }

    //Les deux joueurs ont autant de graines
    if (board.gainJ1 == 32 && board.gainJ2 == 32){
        return true;
    }

    /**
     * au lieu de parcourir le tableau pour déterminer s'il reste
     * strictement moins de 8 on compte les graines des 2 joueurs 
     * ça économise de parcourir le tableau après chaque coups.
     */
    if (board.gainJ1 + board.gainJ2 > 56){ //56 vaut 64 - 8
        return true;
    }

    //Un des deux joueurs est mort de faim
    if (board.is_a_player_starving() >= 0){
        return true;
    }
    return false;
}

int winner(Board board){
    if (board.gainJ1 == board.gainJ2){
        return 2; //2 signifie match nul
    }
    if (board.gainJ1 > board.gainJ2){
        return 0; //0 signifie que le joueur 1 a gagné
    }else{
        return 1; //1 signifie que le joueur 2 a gagné
    }
    return -1; //Cas d'erreur
}