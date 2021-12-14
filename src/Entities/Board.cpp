#include <sstream>
#include "Trou.cpp"
#include "Move.cpp"
class Board {

    public:           
        //constructeurs
        Board();

        //variables
        Trou *cases;
        short gainJ1;
        short gainJ2;
        bool ingame;

        //fonctions
        bool currentPlayerIsStarving(int);
        void printer();
        void copy(Board b);
};

/**
 * Constructeur
 */ 
Board::Board() {
    cases = new Trou[16];
    gainJ1 = 0;
    gainJ2 = 0;
    ingame = true;
}

/**
 * Affiche le board
 */ 
void Board::printer(){
    std::cout << "Affichage du board : [\n";
    int cpt=1;
    for(int i = 0; i < 16; i++){

        std::cout << cases[i].toString(i+1) << ", ";
        if (cpt%8==0){
            std::cout << "\n";
        }
        cpt++;
    }
    std::cout << "]" <<std::endl;
}


bool Board::currentPlayerIsStarving(int currentPlayer){
    int sommeGraines=0;

    for(int i = 0; i<16; i++){
        if (i%2 == currentPlayer){
            sommeGraines += cases[i].graine_bleu + cases[i].graine_rouge;
            
        }
    }
    return sommeGraines == 0;
}

//deep copy of board
void Board::copy(Board b){
    
    this->ingame = b.ingame;
    this->gainJ2 = b.gainJ2;
    this->gainJ1 = b.gainJ1;
    for (int i = 0; i < 16; i++){
        this->cases[i] = b.cases[i];
    }
}