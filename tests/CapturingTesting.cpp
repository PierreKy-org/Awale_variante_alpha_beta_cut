#include <sstream>
#include "../src/CapturingRules.cpp"

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
    
    board.printer();
    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge = 0;
    comparisonBoard.cases[2].graine_rouge = 0;
    comparisonBoard.cases[3].graine_rouge = 0;

    comparisonBoard.cases[0].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu = 0;
    comparisonBoard.cases[2].graine_bleu = 0;
    comparisonBoard.cases[3].graine_bleu = 0;
    comparisonBoard.printer();

    //Le joueur aura gagné 6 graines
    comparisonBoard.gainJ1 = 8;
    printf("%d uwu %d uwu %d uwu %d",board.gainJ1, board.gainJ2, comparisonBoard.gainJ1, comparisonBoard.gainJ2);
    return compareTwoCases(board.cases, comparisonBoard.cases) && (board.gainJ1 == comparisonBoard.gainJ1);
}

int testing (char* functionName, bool (*function)()){
    printf("\nTesting %s : \n", functionName);
    if (function()){
        printf("Test Passed\n");
        return 1;
    } else {
        printf("Test Failed     !!!!!!!!!!!!!!!!!!!!!!\n");
        return 0;
    }
}

int main(){
    int successes = 0;
    successes += testing("testCapturing01", &capturingTest01);

    printf("\n\n=====> [%d/3] Test Passed\n", successes);
}