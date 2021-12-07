#include <sstream>
#include "../src/Rules/CapturingRules.cpp"

/**
 * Fonction just pour les tests
 * permet de comparer deux tableaux de trous
 */
bool compareTwoCases(Trou case1[16], Trou case2[16]){
    for (int i=0; i < 16; i++){
        if (!(case1[i].equals(case2[i]))){
            return false;
        }
    }
    return true;
}

/**
 * Test un gros essaimage (qui ne fait pas tour complet) de graines rouges
 */ 
bool capturingTest01(){
    int joueur = 0;
    Board board;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)

    board.cases[3].graine_bleu = 0;
    board.cases[2].graine_bleu = 0;
    board.cases[1].graine_bleu = 0;
    board.cases[0].graine_bleu = 0;

    board = capture(board, 3, 0);
    
    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge = 0;
    comparisonBoard.cases[2].graine_rouge = 0;
    comparisonBoard.cases[3].graine_rouge = 0;

    comparisonBoard.cases[0].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu = 0;
    comparisonBoard.cases[2].graine_bleu = 0;
    comparisonBoard.cases[3].graine_bleu = 0;

    //Le joueur aura gagné 8 graines
    comparisonBoard.gainJ1 = 8;
    return compareTwoCases(board.cases, comparisonBoard.cases) && (board.gainJ1 == comparisonBoard.gainJ1);
}

/**
 * Vérification du retour en arrière (passer de 0 à 15,14,... )
 * 
 */ 
bool capturingTest02(){
    int joueur = 0;
    Board board;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)

    board.cases[15].graine_bleu = 0;
    board.cases[3].graine_bleu = 0;
    board.cases[2].graine_bleu = 0;
    board.cases[1].graine_bleu = 0;
    board.cases[0].graine_bleu = 0;

    board = capture(board, 3, 0);
    int i = (-1%16);

    comparisonBoard.cases[15].graine_rouge = 0;
    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge = 0;
    comparisonBoard.cases[2].graine_rouge = 0;
    comparisonBoard.cases[3].graine_rouge = 0;

    comparisonBoard.cases[15].graine_bleu = 0;
    comparisonBoard.cases[0].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu = 0;
    comparisonBoard.cases[2].graine_bleu = 0;
    comparisonBoard.cases[3].graine_bleu = 0;

    //Le joueur aura gagné 10 graines
    comparisonBoard.gainJ1 = 10;
    return compareTwoCases(board.cases, comparisonBoard.cases) && (board.gainJ1 == comparisonBoard.gainJ1);
}

/**
 * Test de non capture, 
 * Malgré le fait que beaucoup de case puissent être
 * prises.
 * On ne les prends pas car un case au début ne peut pas être prise.
 */
bool capturingTest03(){
    int joueur = 0;
    Board board;
    Board comparisonBoard; 

    board.cases[4].graine_bleu = 0;
    //Ici la case[3] n'est pas changée (elle vaut donc 4)
    board.cases[2].graine_bleu = 0;
    board.cases[1].graine_bleu = 0;
    board.cases[0].graine_bleu = 0;

    board = capture(board, 4, 0);
    
    //On ne peut prendre que depuis 4 du coup (vu que 3 fonctionne)
    comparisonBoard.cases[4].graine_rouge = 0;
    comparisonBoard.cases[4].graine_bleu = 0;
    comparisonBoard.cases[2].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu = 0;
    comparisonBoard.cases[0].graine_bleu = 0;

    //Le joueur aura gagné 2 graines
    comparisonBoard.gainJ1 = 2;
    return compareTwoCases(board.cases, comparisonBoard.cases) && (board.gainJ1 == comparisonBoard.gainJ1);
}

int testing (char* functionName, bool (*function)(), bool quiet=true){
    if (!quiet) {printf("\nTesting %s : \n", functionName);}
    if (function()){
        if (!quiet) {printf("Test Passed\n");}
        return 1;
    } else {
        if (!quiet) {printf("Test Failed     !!!!!!!!!!!!!!!!!!!!!!\n");}
        return 0;
    }
}

int main(){
    int successes = 0;
    successes += testing("testCapturing01", &capturingTest01);
    successes += testing("testCapturing02", &capturingTest02);
    successes += testing("testCapturing03", &capturingTest03);

    printf("\n\n=====> [%d/3] Test Passed\n", successes);
}