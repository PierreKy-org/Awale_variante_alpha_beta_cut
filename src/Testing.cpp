#include <sstream>
#include "TestingBoards.cpp"


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
    Board board;
    Move move(0, 'B');
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

void testing (char* functionName, bool (*function)()){
    printf("\nTesting %s : \n", functionName);
    if (function()){
        printf("Test Passed\n");
    } else {
        printf("Test Failed     !!!!!!!!!!!!!!!!!!!!!!\n");
    }
}

int main(){
    Board board;
    testing("testMoveParser01", &testMoveParser01);
    testing("testMoveParser02", &testMoveParser02);
    testing("testMoveParser03", &testMoveParser03);
    testing("testLegal01", &testLegal01);
    testing("testLegal02", &testLegal02);
    testing("testIllegal01", &testIllegal01);
    testing("testIllegal02", &testIllegal02);
    testing("testIllegal03", &testIllegal03);
}