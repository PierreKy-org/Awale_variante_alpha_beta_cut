#include <sstream>
#include "../src/Rules/CapturingRules.cpp"



/**
 * Test copie des gains J1 et J2
 */ 
bool testCopy01(){
    Board board;
    //On ajoute des graines
    board.gainJ1 = 50;
    board.gainJ2 = 50;
    Board b;
    b.copy(board);
    //Modification de la copie
    b.gainJ1 = 20;
    b.gainJ2 = 20;
    return (b.gainJ1 == 20 && b.gainJ2 == 20 && board.gainJ1 == 50 && board.gainJ2 == 50); 
}

/**
 * Test de copie du board.ingame
 */ 
bool testCopy02(){
    Board board;
    //On ajoute des graines
    board.ingame = true;
    Board b;
    b.copy(board);
    //Modification de la copie
    b.ingame = false;


    return (!b.ingame && board.ingame); 
}


/**
 * Test de copie du plateau
 */ 
bool testCopy03(){
    Board board;
    //On ajoute des graines
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
    Board b;
    b.copy(board);

    //Modification de la copie
    b.cases[0].graine_rouge = 2;



    return (b.cases[0].graine_rouge == 2 && board.cases[0].graine_rouge == 0); 
}


/**
 * Test de copie du plateau avec une modifcation par execute_a_move
 */ 
bool testCopy04(){
    Board board;
    //On ajoute des graines
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
    Board b;
    b.copy(board);

    //Modification de la copie
    Move r = Move(1,'R');
    if(is_a_move_legal(b, r, 1)){
        int x = execute_a_move(b, r, 1);
    }


    return (b.cases[1].graine_rouge == 0 && board.cases[1].graine_rouge == 2); 
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

//IL MANQUE DES TESTS qui nécessite l'implémentation de la capture
// : Déterminer le gagnant APRES un coup décisif niveau capture

int main(){
    int successes = 0;
    successes += testing("testCopy01", &testCopy01);
    successes += testing("testCopy02", &testCopy02);
    successes += testing("testCopy03", &testCopy03);
    successes += testing("testCopy04", &testCopy04);




    printf("\n\n=====> [%d/4] Test Passed\n", successes);
}
