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

bool compareM(Move a, Move b){

    return a.getGain() >  b.getGain();
}


std::tuple<std::vector<Move>, int> allMoves(Board board, int joueur){
    std::vector<Move> listMoves;
    int cpt = 0;
    //TODO OPTIMISATION PASSER PAR 1 TROU SUR 2 
    for(int i = joueur; i < 16; i+=2){
        Move current_moveR(i,'R');
        Move current_moveB(i,'B');
        if(is_a_move_legal(board, current_moveR, joueur)){
            listMoves.push_back(current_moveR);
            cpt++;
        }
        
        if(is_a_move_legal(board, current_moveB, joueur)){
            listMoves.push_back(current_moveB);
            cpt++;
        }
    }
    return {listMoves,cpt};
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

    auto [moves, size] = allMoves(board, joueur);
    std::vector<Move> tab_valeurs;

    int cpt = 1;
    for(int i=0;i<size;i++){
        b.copy(board);
       
        Move currentMove = moves[i];
        int casse =  execute_a_move(b,moves[i], joueur);
        b = capture(b,casse, joueur);
        tab_valeurs.push_back(valeurMinMax(b, (joueur+1)%2,prof+1,profMax, currentMove));
        cpt++;
        
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

