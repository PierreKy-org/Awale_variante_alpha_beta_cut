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
        int is_a_player_starving();
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

int Board::is_a_player_starving(){
    int j1_starving = 0;
    int j2_starving = 0;
    int grainesDeLaCase;

    for(int i=0; i<16; i++){
        if (j1_starving > 0 && j2_starving > 0){
            //Les deux joueurs ont des graines, aucun ne starve
            return -1;
        }
        grainesDeLaCase = cases[i].graine_bleu + cases[i].graine_rouge;
        //printf("graines : %d\n",grainesDeLaCase);
        if(i%2 == 0){
            j1_starving = j1_starving + grainesDeLaCase;
        }else{
            j2_starving = j2_starving + grainesDeLaCase;
        }
    }

    //Un player starve
    if(j1_starving == 0){
        return 0;

    }
    else{
        return 1;
    }
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