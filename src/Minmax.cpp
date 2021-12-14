// A simple C++ program to find
// maximum score that
// maximizing player can get.
#include<bits/stdc++.h>
#include<iterator>
#include <tuple>
#include <algorithm>
#include <vector>
#include "Rules/CapturingRules.cpp"

using namespace std;

bool compare(Move a, Move b){

    return a.getGain() <  b.getGain();
}
int TOTAL_NUMBERS_OF_POSITIONS = 0;
bool compareM(Move a, Move b){

    return a.getGain() >  b.getGain();
}


std::vector<Move> allMoves(Board board, int joueur){
    std::vector<Move> listMoves;
    //printf("Current player in all moves : %d\n", joueur);
    for(int i = 0; i < 16; i++){
        Move current_moveR(i,'R');
        Move current_moveB(i,'B');
        if(is_a_move_legal(board, current_moveR, joueur)){
            listMoves.push_back(current_moveR);
        }
        if(is_a_move_legal(board, current_moveB, joueur)){
            listMoves.push_back(current_moveB);
        }
    }

    TOTAL_NUMBERS_OF_POSITIONS+= listMoves.size();
    return  listMoves;
}
int evaluation(Board board){
    return board.gainJ1-board.gainJ2;
}


Move valeurMinMax(Board board, int joueur, int prof, int profMax, Move move){
    Board b;
    if (prof == profMax) {
            move.setGain(evaluation(board));
            return move;
    }
    std::vector<Move> moves = allMoves(board, joueur);
    std::vector<Move> tab_valeurs;
    for(int i=0;i<moves.size()-1;i++){
        b.copy(board);
       
        Move currentMove = moves[i];
        int casse =  execute_a_move(b,moves[i], joueur);
        b = capture(b,casse, joueur);
        tab_valeurs.push_back(valeurMinMax(b, (joueur+1)%2,prof+1,profMax, currentMove));
        
    }
    Move res(19,'Y');
    if (joueur == 0) {
            res = *std::max_element(std::begin(tab_valeurs), std::end(tab_valeurs), compare);
            
    } 
    else {
        res= *std::min_element(std::begin(tab_valeurs), std::end(tab_valeurs), compare); 
       
    }
    return res;
}

