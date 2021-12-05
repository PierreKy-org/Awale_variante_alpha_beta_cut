#include <sstream>
#include "Rules.cpp"


//Un seul digit avant le B
bool testMoveParser01(){
    Move move = parse_a_move("3B");
    return (move.starting_hole == 3
        && move.color == 'B');
}
//Plusieurs digits
bool testMoveParser02(){
    Move move = parse_a_move("9999B");
    return (move.starting_hole == 9999
        && move.color == 'B');
}
//Couleur inconnue
bool testMoveParser03(){
    Move move = parse_a_move("15Z");
    return (move.starting_hole == -1
        && move.color == '0');
}

/**
 * Move legal car on commence à partir d'une case pair en etant joueur 1
 */
bool testLegal01(){
    Move move(0, 'B');
    Board board;
    int joueur = 0;
    return is_a_move_legal(board, move, joueur);
}   

/**
 * Move legal car on prend des billes case qui les contient et qui nous appartient
 */
bool testLegal02(){
    Board board;
    Move moveB(0, 'B');
    Move moveR(0, 'R');
    int joueur = 0;
    bool legalB = is_a_move_legal(board, moveB, joueur);
    bool legalR = is_a_move_legal(board, moveR, joueur);
    return (legalB && legalR);
}

/**
 * Move illegal car on commence à partir d'une case pair alors qu'on est le joueur 2
 */
bool testIllegal01(){
    Board board;
    Move move(0, 'B');
    int joueur = 1;
    return (is_a_move_legal(board, move, joueur) == false);
}

/**
 * Move illegal car on prend des billes rouges d'une case qui n'en a pas
 */
bool testIllegal02(){
    int joueur = 0;

    Board board;
    board.cases[0].graine_rouge = 0;

    Move move(0, 'R');
    return (is_a_move_legal(board, move, joueur) == false);
}

/**
 * Move illegal car on prend des billes bleues d'une case qui n'en a pas
 */
bool testIllegal03(){
    int joueur = 0;

    Board board;
    board.cases[0].graine_bleu = 0;

    Move move(0, 'B');
    return (is_a_move_legal(board, move, joueur) == false);
}

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
 * Test qu'on enlève bien les graines de la case de départ
 * Accessoirement il vérifie qu'on déplace bien les graines rouges
 */ 
bool testAfterMakingMove01(){
    int joueur = 0;
    Board board;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)
    Move move(0, 'R');

    execute_a_move(board, move, joueur);

    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge += 1;
    comparisonBoard.cases[2].graine_rouge += 1;

    return compareTwoCases(board.cases, comparisonBoard.cases);
}
/**
 * Test qu'on sow bien les graines bleues
 */ 
bool testAfterMakingMove02(){
    int joueur = 0;
    Board board;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)
    Move move(0, 'B');

    execute_a_move(board, move, joueur);

    comparisonBoard.cases[0].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu += 1;
    comparisonBoard.cases[3].graine_bleu += 1;

    return compareTwoCases(board.cases, comparisonBoard.cases);
}

/**
 * Test un gros essaimage (qui ne fait pas tour complet) de graines rouges
 */ 
bool testAfterMakingMove03(){
    int joueur = 0;
    Board board;
    //on rajoute plein de graines dans la case de départ
    board.cases[0].graine_rouge = 10;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)
    Move move(0, 'R');

    execute_a_move(board, move, joueur);
    //board.printer();

    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge += 1;
    comparisonBoard.cases[2].graine_rouge += 1;
    comparisonBoard.cases[3].graine_rouge += 1;
    comparisonBoard.cases[4].graine_rouge += 1;
    comparisonBoard.cases[5].graine_rouge += 1;
    comparisonBoard.cases[6].graine_rouge += 1;
    comparisonBoard.cases[7].graine_rouge += 1;
    comparisonBoard.cases[8].graine_rouge += 1;
    comparisonBoard.cases[9].graine_rouge += 1;
    comparisonBoard.cases[10].graine_rouge += 1;
    //comparisonBoard.printer();

    return compareTwoCases(board.cases, comparisonBoard.cases);

}

/**
 * Test un gros essaimage de graines bleues
 */ 
bool testAfterMakingMove04(){
    int joueur = 0;
    Board board;
    //on rajoute plein de graines dans la case de départ
    board.cases[0].graine_bleu = 10;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)
    Move move(0, 'B');

    execute_a_move(board, move, joueur);
    //board.printer();

    comparisonBoard.cases[0].graine_bleu = 0;
    comparisonBoard.cases[1].graine_bleu += 1;
    comparisonBoard.cases[3].graine_bleu += 1;
    comparisonBoard.cases[5].graine_bleu += 1;
    comparisonBoard.cases[7].graine_bleu += 1;
    comparisonBoard.cases[9].graine_bleu += 1;
    comparisonBoard.cases[11].graine_bleu += 1;
    comparisonBoard.cases[13].graine_bleu += 1;
    comparisonBoard.cases[15].graine_bleu += 1;
    comparisonBoard.cases[1].graine_bleu += 1;
    comparisonBoard.cases[3].graine_bleu += 1;

    //comparisonBoard.printer();
    return compareTwoCases(board.cases, comparisonBoard.cases);
 
}

/**
 * Test qu'on ne repasse pas sur la case de départ si on essaime beaucoup de graine
 */ 
bool testAfterMakingMove05(){
    int joueur = 0;
    Board board;
    //on rajoute plein de graines dans la case de départ
    board.cases[0].graine_rouge = 16;
    Board comparisonBoard; //Board qui contiendra le résultat attendu (est comparé avec le premier)
    Move move(0, 'R');

    execute_a_move(board, move, joueur);
    //board.printer();

    comparisonBoard.cases[0].graine_rouge = 0;
    comparisonBoard.cases[1].graine_rouge += 1;
    comparisonBoard.cases[2].graine_rouge += 1;
    comparisonBoard.cases[3].graine_rouge += 1;
    comparisonBoard.cases[4].graine_rouge += 1;
    comparisonBoard.cases[5].graine_rouge += 1;
    comparisonBoard.cases[6].graine_rouge += 1;
    comparisonBoard.cases[7].graine_rouge += 1;
    comparisonBoard.cases[8].graine_rouge += 1;
    comparisonBoard.cases[9].graine_rouge += 1;
    comparisonBoard.cases[10].graine_rouge += 1;
    comparisonBoard.cases[11].graine_rouge += 1;
    comparisonBoard.cases[12].graine_rouge += 1;
    comparisonBoard.cases[13].graine_rouge += 1;
    comparisonBoard.cases[14].graine_rouge += 1;
    comparisonBoard.cases[15].graine_rouge += 1;
    comparisonBoard.cases[1].graine_rouge += 1;
    //comparisonBoard.printer();

    return compareTwoCases(board.cases, comparisonBoard.cases);

}

void testing (char* functionName, bool (*function)()){
    printf("\nTesting %s : \n", functionName);
    if (function()){
        printf("Test Passed\n");
    } else {
        printf("Test Failed     !!!!!!!!!!!!!!!!!!!!!!\n");
    }
}

int main(){
    testing("testMoveParser01", &testMoveParser01);
    testing("testMoveParser02", &testMoveParser02);
    testing("testMoveParser03", &testMoveParser03);

    testing("testLegal01", &testLegal01);
    testing("testLegal02", &testLegal02);

    testing("testIllegal01", &testIllegal01);
    testing("testIllegal02", &testIllegal02);
    testing("testIllegal03", &testIllegal03);
    
    testing("testAfterAMove01", &testAfterMakingMove01);
    testing("testAfterAMove02", &testAfterMakingMove02);
    testing("testAfterAMove03", &testAfterMakingMove03);
    testing("testAfterAMove04", &testAfterMakingMove04);
    testing("testAfterAMove05", &testAfterMakingMove05);
}