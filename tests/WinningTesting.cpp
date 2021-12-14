#include <sstream>
#include "../src/Rules/WinningRules.cpp"



/**
 * Test de condition de fin : Partie gagnée par le joueur 1
 */ 
bool testEndGame01(){
    Board board;

    //On modifie le gain
    //Les gains sont des chars (il faut pas mettre plus de 256 dedans du coup)
    board.gainJ1 = 50;

    return is_it_the_end_of_the_game(board);
}
/**
 * Test de condition de fin : Partie gagnée par le joueur 2
 */ 
bool testEndGame02(){
    Board board;

    //On modifie le gain
    board.gainJ2 = 50;

    return is_it_the_end_of_the_game(board);
}

/**
 * Test de condition de fin : Partie nulle par égalité
 */ 
bool testEndGame03(){
    Board board;

    board.gainJ1 = board.gainJ2 = 32;

    return is_it_the_end_of_the_game(board);
}

/**
 * Test de condition de fin : Il reste strictement moins de 8 billes
 */ 
bool testEndGame04(){
    Board board;
    //on vérifie par les gains des joueurs et non par le tableau
    board.gainJ1 = board.gainJ2 = 30;

    return is_it_the_end_of_the_game(board);
}

/**
 * test que la partie n'EST PAS finie
 */ 
bool testEndGame05(){
    Board board;

    board.gainJ1 = board.gainJ2 = 28;//28 graines chacun c'est juste en dessous de la nulle (64-8)

    return !(is_it_the_end_of_the_game(board));
}

/**
 * test du starving joueur 2 
 */ 
bool testEndGame06(){
    Board board;
    board.gainJ1 = board.gainJ2 = 0;
    //Les gains sont à 0 pour ne pas interférer

    //Le joueur 1 (case[0]) possède plein de graines
    //Le joueur 2 n'en as aucunes
    board.cases[0].graine_bleu = 2;
    board.cases[0].graine_rouge = 2;
    board.cases[1].graine_bleu = 0;
    board.cases[1].graine_rouge = 0;
    board.cases[2].graine_bleu = 0;
    board.cases[2].graine_rouge = 0;
    board.cases[3].graine_bleu = 0;
    board.cases[3].graine_rouge = 0;
    board.cases[4].graine_bleu = 0;
    board.cases[4].graine_rouge = 0;
    board.cases[5].graine_bleu = 0;
    board.cases[5].graine_rouge = 0;
    board.cases[6].graine_bleu = 0;
    board.cases[6].graine_rouge = 0;
    board.cases[7].graine_bleu = 0;
    board.cases[7].graine_rouge = 0;
    board.cases[8].graine_bleu = 0;
    board.cases[8].graine_rouge = 0;
    board.cases[9].graine_bleu = 0;
    board.cases[9].graine_rouge = 0;
    board.cases[10].graine_bleu = 0;
    board.cases[10].graine_rouge = 0;
    board.cases[11].graine_bleu = 0;
    board.cases[11].graine_rouge = 0;
    board.cases[12].graine_bleu = 0;
    board.cases[12].graine_rouge = 0;
    board.cases[13].graine_bleu = 0;
    board.cases[13].graine_rouge = 0;
    board.cases[14].graine_bleu = 0;
    board.cases[14].graine_rouge = 0;
    board.cases[15].graine_bleu = 0;
    board.cases[15].graine_rouge = 0;
    if(is_it_the_end_of_the_game(board)){
        int result = board.is_a_player_starving();
        if(result == 1){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}


/**
 * Autre test de starving les joueurs ont 1 rouge et 1 bleu
 * Le starving ne doit pas s'appliquer ici
 */ 
bool testEndGame07(){
    Board board;
    board.gainJ1 = board.gainJ2 = 0;
    //Les gains sont à 0 pour ne pas interférer

    //Le joueur 1 (case[0]) possède plein de graines
    //Le joueur 2 n'en as aucunes
    board.cases[0].graine_bleu = 1;
    board.cases[0].graine_rouge = 0;
    board.cases[1].graine_bleu = 0;
    board.cases[1].graine_rouge = 1;
    board.cases[2].graine_bleu = 0;
    board.cases[2].graine_rouge = 0;
    board.cases[3].graine_bleu = 0;
    board.cases[3].graine_rouge = 0;
    board.cases[4].graine_bleu = 0;
    board.cases[4].graine_rouge = 0;
    board.cases[5].graine_bleu = 0;
    board.cases[5].graine_rouge = 0;
    board.cases[6].graine_bleu = 0;
    board.cases[6].graine_rouge = 0;
    board.cases[7].graine_bleu = 0;
    board.cases[7].graine_rouge = 0;
    board.cases[8].graine_bleu = 0;
    board.cases[8].graine_rouge = 0;
    board.cases[9].graine_bleu = 0;
    board.cases[9].graine_rouge = 0;
    board.cases[10].graine_bleu = 0;
    board.cases[10].graine_rouge = 0;
    board.cases[11].graine_bleu = 0;
    board.cases[11].graine_rouge = 0;
    board.cases[12].graine_bleu = 0;
    board.cases[12].graine_rouge = 0;
    board.cases[13].graine_bleu = 0;
    board.cases[13].graine_rouge = 0;
    board.cases[14].graine_bleu = 0;
    board.cases[14].graine_rouge = 0;
    board.cases[15].graine_bleu = 0;
    board.cases[15].graine_rouge = 0;

    return !(is_it_the_end_of_the_game(board));
}

/**
 * test du starving joueur 1
 */ 
bool testEndGame08(){
    Board board;
    board.gainJ1 = board.gainJ2 = 0;
    //Les gains sont à 0 pour ne pas interférer

    //Le joueur 1 (case[0]) possède plein de graines
    //Le joueur 2 n'en as aucunes
    board.cases[0].graine_bleu = 0;
    board.cases[0].graine_rouge = 0;
    board.cases[1].graine_bleu = 2;
    board.cases[1].graine_rouge = 2;
    board.cases[2].graine_bleu = 0;
    board.cases[2].graine_rouge = 0;
    board.cases[3].graine_bleu = 0;
    board.cases[3].graine_rouge = 0;
    board.cases[4].graine_bleu = 0;
    board.cases[4].graine_rouge = 0;
    board.cases[5].graine_bleu = 0;
    board.cases[5].graine_rouge = 0;
    board.cases[6].graine_bleu = 0;
    board.cases[6].graine_rouge = 0;
    board.cases[7].graine_bleu = 0;
    board.cases[7].graine_rouge = 0;
    board.cases[8].graine_bleu = 0;
    board.cases[8].graine_rouge = 0;
    board.cases[9].graine_bleu = 0;
    board.cases[9].graine_rouge = 0;
    board.cases[10].graine_bleu = 0;
    board.cases[10].graine_rouge = 0;
    board.cases[11].graine_bleu = 0;
    board.cases[11].graine_rouge = 0;
    board.cases[12].graine_bleu = 0;
    board.cases[12].graine_rouge = 0;
    board.cases[13].graine_bleu = 0;
    board.cases[13].graine_rouge = 0;
    board.cases[14].graine_bleu = 0;
    board.cases[14].graine_rouge = 0;
    board.cases[15].graine_bleu = 0;
    board.cases[15].graine_rouge = 0;
    if(is_it_the_end_of_the_game(board)){
        int result = board.is_a_player_starving();
        if(result == 1){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}
int testing (char* functionName, bool (*function)(), bool quiet=false){
    if (!quiet) {printf("\nTesting %s : \n", functionName);}
    if (function()){
        if (!quiet) {printf("Test Passed\n");}
        return 1;
    } else {
        if (!quiet) {printf("Test Failed     !!!!!!!!!!!!!!!!!!!!!!\n");}
        return 0;
    }
}

/**
 * Test de l'annonce du gagnant (j1)
 */ 

bool testWinner01(){
    Board board;

    //On modifie le gain
    //Les gains sont des chars (il faut pas mettre plus de 256 dedans du coup)
    board.gainJ1 = 33;
    board.gainJ2 = 31;

    return (winner(board) == 0);
}
/**
 * Test de l'annonce du gagnant (j2)
 */ 

bool testWinner02(){
    Board board;

    //On modifie le gain
    //Les gains sont des chars (il faut pas mettre plus de 256 dedans du coup)
    board.gainJ2 = 33;
    board.gainJ1 = 31;

    return (winner(board) == 1);
}
/**
 * Test de l'annonce de nulle
 */ 
bool testWinner03(){
    Board board;

    //On modifie le gain
    //Les gains sont des chars (il faut pas mettre plus de 256 dedans du coup)
    board.gainJ2 = 32;
    board.gainJ1 = 32;

    return (winner(board) == 2);
}


//IL MANQUE DES TESTS qui nécessite l'implémentation de la capture
// : Déterminer le gagnant APRES un coup décisif niveau capture

int main(){
    int successes = 0;
    successes += testing("testEndgame01", &testEndGame01);
    successes += testing("testEndgame02", &testEndGame02);
    successes += testing("testEndgame03", &testEndGame03);
    successes += testing("testEndgame04", &testEndGame04);
    successes += testing("testEndgame05", &testEndGame05);
    successes += testing("testEndgame06", &testEndGame06);
    successes += testing("testEndgame07", &testEndGame07);
    successes += testing("testEndgame08", &testEndGame08);

    successes += testing("testWinner01", &testWinner01);
    successes += testing("testWinner02", &testWinner02);
    successes += testing("testWinner03", &testWinner03);

    printf("\n\n=====> [%d/11] Test Passed\n", successes);
    printf("PENSER A RAJOUTER LES TESTS MANQUANTS APRES L'IMPLEMENTATION DE LA CAPTURE\n\n");
}
