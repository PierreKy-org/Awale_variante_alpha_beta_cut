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
int total = 0;
int evaluation(Board board){
    cout << "evaluated at : " << (board.gainJ1 - board.gainJ2) << "\n\n";
    return board.gainJ1 - board.gainJ2;
}
std::vector<Board> allBoards(Board board, int joueur){
    cout << "player : " << joueur;
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
            total++;
        }

        if(is_a_move_legal(board, current_moveB, joueur)){
            Board newBoard;
            newBoard.copy(board);
            int endingPosition =  execute_a_move(newBoard,current_moveB, joueur);
            newBoard = capture(newBoard, endingPosition, joueur);
            listBoard.push_back(newBoard);
            total++;
        }
    }
    //cout << "in function" << listBoard.size();
    return listBoard;
}


int minimax(Board board, int max_depth, int player, int alpha, int beta){
    printf("depth : %d", max_depth);
    if (max_depth == 0 || is_it_the_end_of_the_game(board)){
        printf("going out");
        return evaluation(board);
    }
    if (player == 0){
        printf("here min ");
        int value = -999;
        std::vector<Board> boards = allBoards(board, player);

        for (int i=0; i < boards.size(); i++){
            int evaluation = minimax(
                boards[i], 
                max_depth-1,
                (player+1)%2,
                alpha,
                beta
            );
            value = min(value, evaluation);
            beta = min(beta, evaluation);
            if (beta <= alpha){
                break;
            }
        return value; 
        }
    } else {
        printf("here max\n");
        int value = 999;
        std::vector<Board> boards = allBoards(board, player);
        for (int i; i < boards.size(); i++){
            int evaluation = minimax(
                boards[i],
                max_depth-1,
                (player+1)%2,
                alpha,
                beta
            );

            cout << "\neval value :  " << evaluation;
            value = max(value, evaluation);
            alpha = max(alpha, evaluation);
            if (beta >= alpha){
                break;
            }
        return value; 
        }
    }
}


Move playAMove(Board initialBoard, int joueur, int maxDepth){
    std::map<std::string, int> values;
    for(int i = 0; i < 16; i++){

        Move current_moveR(i,'R');
        Move current_moveB(i,'B');

        if(is_a_move_legal(initialBoard, current_moveR, joueur)){
            int val = minimax(initialBoard, maxDepth, joueur, 0, 0);
            cout << "strange val : "<< val;
            values.insert(std::make_pair(current_moveR.toString(), val));
        }
        if(is_a_move_legal(initialBoard, current_moveB, joueur)){
            int val = minimax(initialBoard, maxDepth, joueur, 0, 0);
            cout << "strange val : "<< val;
            values.insert(std::make_pair(current_moveB.toString(), val));
        }
    }

    int max = -999;
    string maxStr;
    for(const auto& elem : values) {
        std::cout << elem.first << " || " << elem.second << "\n";
    }

    for (auto const& x : values)
    {
        if (x.second > max) {
            max = x.second;
            maxStr = x.first;
        }
    }
    cout << "\nMAXIMUM STR : " <<maxStr;
    Move res = parse_a_move(maxStr);
    res.starting_hole++;
    return res;
}

int main(){
    Board board;

    playAMove(board, 0, 15).printer();
    printf("%d", total);

}