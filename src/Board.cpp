#include <sstream>
#include "Trou.cpp"
#include "Graine.cpp"

class Board {

    public:           
        //Variables
        Trou *cases;
        char gainJ1;
        char gainJ2;
        bool tour;
        bool ingame;

        //Functions
        Board();
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


int deplacementEtGain(Trou* cases, int nb){
    Trou temp = cases[nb];
    int acc = 1;
    int gain = 0;
    return gain; //On renvoi le nombre de graine gagné
}

