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

void testing (char* functionName, bool (*function)()){
    printf("\nTesting %s : \n", functionName);
    if (function()){
        printf("Test Passed\n");
    } else {
        printf("Test Failed\n");
    }
}

int main(){
    Board board;
    testing("testMoveParser01", &testMoveParser01);
    testing("testMoveParser02", &testMoveParser02);
    testing("testMoveParser03", &testMoveParser03);
}