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

int evaluation(Board board){
    return board.gainJ1 - board.gainJ2;
}
std::vector<Board> allBoards(Board board, int joueur){
    std::vector<Board> listBoard;
    for(int i = 0; i < 16; i++){

        Move current_moveR(i,'R');
        Move current_moveB(i,'B');

        if(is_a_move_legal(board, current_moveR, joueur)){
            Board newBoard;
            newBoard.copy(board);
            int endingPosition =  execute_a_move(newBoard,current_moveR, joueur);
            newBoard = capture(newBoard, endingPosition, joueur);
            listBoard.push_back(newBoard);
        }

        if(is_a_move_legal(board, current_moveB, joueur)){
            Board newBoard;
            newBoard.copy(board);
            int endingPosition =  execute_a_move(newBoard,current_moveB, joueur);
            newBoard = capture(newBoard, endingPosition, joueur);
            listBoard.push_back(newBoard);
        }
    }
    return listBoard;
}


int minimax(Board board, int max_depth, int is_player_minimizer, int alpha, int beta){
    if (max_depth == 0 || is_it_the_end_of_the_game(board)){
        return evaluation(board);
    }

    if (is_player_minimizer == 0){
        int value = -999;
        int evaluation = 999;
        std::vector<Board> boards = allBoards(board, is_player_minimizer);
        for (int i; i < boards.size(); i++){
            evaluation = minimax(
                board, 
                max_depth-1,
                (is_player_minimizer++)%2,
                alpha,
                beta
            );
            int mini = min(value, evaluation);
            beta = min(beta, evaluation);
            if (beta <= alpha){
                break;
            }
        return value; 
        }
    } else {
        int value = 999;
        int evaluation = -999;
        std::vector<Board> boards = allBoards(board, is_player_minimizer);
        for (int i; i < boards.size(); i++){
            evaluation = minimax(
                board,
                max_depth-1,
                (is_player_minimizer++)%2,
                alpha,
                beta
            );

            int maxi = max(value, evaluation);
            alpha = max(alpha, evaluation);
            if (beta <= alpha){
                break;
            }
        return value; 
        }
    }
}


Move playAMove(Board initialBoard, int joueur, int maxDepth){
    std::map<std::string, int> values;
    for(int i = 0; i < 16; i++){

        char buffer_moveR[4];
        sprintf(buffer_moveR, "%d%c",i,'R');
        string moveR(buffer_moveR); 

        char buffer_moveB[4];
        sprintf(buffer_moveB, "%d%c",i,'B');
        string moveB(buffer_moveR); 

        Move current_moveR = parse_a_move(buffer_moveR);
        if(is_a_move_legal(initialBoard, current_moveR, joueur)){
            int val = minimax(initialBoard, maxDepth, joueur, -999, 999);
            values.insert(std::make_pair(moveR, val));
        }
        Move current_moveB = parse_a_move(buffer_moveB);
        if(is_a_move_legal(initialBoard, current_moveB, joueur)){
            int val = minimax(initialBoard, maxDepth, joueur, -999, 999);
            values.insert(std::make_pair(moveB, val));
        }
    }

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

int main(){
    Board board;

    playAMove(board, 0, 15).printer();

}