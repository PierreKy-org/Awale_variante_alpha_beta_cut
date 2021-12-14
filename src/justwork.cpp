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
        
    if(profondeur == profondeurMax || is_it_the_end_of_the_game(board)){
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
}
Move playAMove(Board initialBoard, int joueur, int maxDepth){
    std::map<std::string, int> values;
    int depth = 0;
    for(int i = 0; i < 16; i++){

        char buffer_moveR[4];
        sprintf(buffer_moveR, "%d%c",i,'R');
        string moveR(buffer_moveR); 

        char buffer_moveB[4];
        sprintf(buffer_moveB, "%d%c",i,'B');
        string moveB(buffer_moveR); 

        Move current_moveR = parse_a_move(buffer_moveR);
        if(is_a_move_legal(initialBoard, current_moveR, joueur)){
            int val = valeurMinMax(initialBoard, joueur, depth,maxDepth);
            values.insert(std::make_pair(moveR, val));
        }
        Move current_moveB = parse_a_move(buffer_moveB);
        if(is_a_move_legal(initialBoard, current_moveB, joueur)){
            int val = valeurMinMax(initialBoard, joueur, depth, maxDepth);
            values.insert(std::make_pair(moveB, val));
        }
    }

    //TODO faire le min pour quand on est J2
    int max = -999;
    string maxStr;
    for (auto const& x : values)
    {
        if (x.second > max) {
            max = x.second;
            maxStr = x.first;
        }
    }
    return parse_a_move(maxStr);
}