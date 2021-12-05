#include <sstream>
#include "Trou.cpp"
#include "Graine.cpp"

class Board {

    public:           
        //constructeurs
        Board();

        //variables
        Trou *cases;
        char gainJ1;
        char gainJ2;
        bool tour;
        bool ingame;

        //fonctions
        int is_a_player_starving();
        void printer();
};

/**
 * Constructeur
 */ 
Board::Board() {
    cases = new Trou[16];
    gainJ1 = 0;
    gainJ2 = 0;
    tour = true;
    ingame = true;
}

/**
 * Affiche le board
 */ 
void Board::printer(){
    std::cout << "[ ";
    for(int i = 0; i < 16; i++){
        std::cout << cases[i].toString() << ", ";
    }
    std::cout << "]" <<std::endl;
}

int Board::is_a_player_starving(){
    int j1_starving;
    int j2_starving;

    for(int i=0; i<16; i++){
        if(i%2 == 0){
            j1_starving += cases[i].graine_bleu + cases[i].graine_rouge;
        }else{
            j2_starving += cases[i].graine_bleu + cases[i].graine_rouge;
        }
    }
    return (j1_starving == 0 || j2_starving == 0);
}





