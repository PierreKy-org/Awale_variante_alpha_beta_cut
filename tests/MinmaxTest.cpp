#include <sstream>
#include "../src/Minmax.cpp"



/**
 * Test un gros essaimage (qui ne fait pas tour complet) de graines rouges
 */ 
bool capturingTest01(){
    int joueur = 0;
    Board board;


    board.cases[15].graine_bleu = 1;
    board.cases[14].graine_bleu = 1;
    board.cases[13].graine_bleu = 1;
    board.cases[12].graine_bleu = 1;
    board.cases[11].graine_bleu = 1;
    board.cases[10].graine_bleu = 1;
    board.cases[9].graine_bleu = 1;
    board.cases[8].graine_bleu = 1;
    board.cases[7].graine_bleu = 1;
    board.cases[6].graine_bleu = 1;
    board.cases[5].graine_bleu = 1;
    board.cases[4].graine_bleu = 1;
    board.cases[3].graine_bleu = 1;
    board.cases[2].graine_bleu = 1;
    board.cases[1].graine_bleu = 1;
    board.cases[0].graine_bleu = 1;
    
    board.cases[0].graine_rouge = 0;
    board.cases[1].graine_rouge = 0;
    board.cases[2].graine_rouge = 2;
    board.cases[3].graine_rouge = 0;
    board.cases[4].graine_rouge = 0;
    board.cases[5].graine_rouge = 0;
    board.cases[6].graine_rouge = 0;
    board.cases[7].graine_rouge = 0;
    board.cases[8].graine_rouge = 8;
    board.cases[9].graine_rouge = 0;
    board.cases[10].graine_rouge = 0;
    board.cases[11].graine_rouge = 0;
    board.cases[12].graine_rouge = 0;
    board.cases[13].graine_rouge = 0;
    board.cases[14].graine_rouge = 0;
    board.cases[15].graine_rouge = 0;


    Move x = valeurMinMax(board, 0,0,1,Move(19, 'Y'));
    x.printer();
    if(x.color == 'R' && x.starting_hole == 8){
        return true;
    }
    else{
        return false;
    }
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


    printf("\n\n=====> [%d/1] Test Passed\n", successes);
}