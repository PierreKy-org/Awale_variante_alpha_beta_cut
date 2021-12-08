#include <sstream>
#include "Trou.cpp"

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
    std::cout << "Affichage du board : [\n";
    int cpt=1;
    for(int i = 0; i < 16; i++){

        std::cout << cases[i].toString() << ", ";
        if (cpt%4==0){
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
            return false;
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
    return true;

    return (j1_starving == 0 || j2_starving == 0);
}





