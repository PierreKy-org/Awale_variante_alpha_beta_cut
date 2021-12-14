#include<bits/stdc++.h>
#include<iterator>
#include <tuple>
#include <algorithm>
#include <vector>
#include "Rules/CapturingRules.cpp"

using namespace std;

int TOTAL_NUMBERS_OF_POSITIONS = 0;
std::vector<Move> allMoves(Board board, int joueur){
    std::vector<Move> listMoves;
    //TODO OPTIMISATION PASSER PAR 1 TROU SUR 2 
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


int valeurMinMax(Board board, int joueur, int profondeur, int profondeurMax){
        
    if(profondeur == profondeurMax){
        return evaluation(board);
    }
    int value;
    std::vector<Move> moves = allMoves(board, joueur);
    Board b;
    if(joueur == 0){ //MAX
        value = -59;
        for(int i=0; i< moves.size(); i++){
            //NEED TOUT LES FILS
            b.copy(board);
            int x = execute_a_move(b, moves[i],joueur);
            b = capture(b,x,joueur);
            int eval = valeurMinMax(b, (joueur+1)%2, profondeur+1, profondeurMax);
            value = std::max(value, eval);
            
        }
        return value;
    }
    else { //MIN
        value = 50;
        for(int i=0; i< moves.size(); i++){
            //NEED TOUT LES FILS
            b.copy(board);
            int x = execute_a_move(b, moves[i],joueur);
            b = capture(b,x,joueur);
            int eval = valeurMinMax(b, (joueur+1)%2, profondeur+1, profondeurMax);
            value = std::min(value, eval);
        }
        return value;
    }