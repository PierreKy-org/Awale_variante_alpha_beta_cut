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
int player;

int evaluation(Board board){
    //cout << "evaluated at : " << (board.gainJ1 - board.gainJ2) <<"\n\n";
    if(player == 0){
        return board.gainJ1 - board.gainJ2;
    } else {
        return board.gainJ2 - board.gainJ1;
    }
}

std::vector<Board> allBoards(Board board, int joueur){
    //cout << "player : " << joueur;
    std::vector<Board> listBoard;
    int i = 0;
    for(i = 0; i < 16; i++){
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
   // cout << "\n nombre de coups : " << listBoard.size() << "\n";
    //board.printer();
    return listBoard;
}

int alphabeta(Board board, int joueur, int profondeur, int alpha, int beta){
   // cout<< "profondeur = " << profondeur;
    if (profondeur == 0 || is_it_the_end_of_the_game(board) || board.currentPlayerIsStarving(joueur)){
        return evaluation(board);
    }

    if (joueur == 0){
        int v = -INFINITY;
        std::vector<Board> boards = allBoards(board, joueur);
        for (Board b : boards){
         
            v = max(v,alphabeta(b, (joueur+1)%2, (profondeur-1), alpha, beta));
            
            if(v >= beta){
                break;
            }
            alpha = max(alpha, v);
        }
        return v;
    }
    else {
        int v = INFINITY;
        std::vector<Board> boards = allBoards(board, joueur);
        for (Board b : boards){
           
            v = min(v, alphabeta(b, (joueur+1)%2, (profondeur-1), alpha, beta));
            if (v <= alpha){
                break;
            }
            beta = min(beta, v);
        }
        return v;
    }
}


Move playAMove(Board initialBoard, int joueur, int maxDepth){
    std::map<std::string, int> values;
    player = joueur;
    for(int i = 0; i < 16; i++){
        int depth = maxDepth;

        Move current_moveR(i,'R');
        Move current_moveB(i,'B');

        if(is_a_move_legal(initialBoard, current_moveR, joueur)){
            Board x;
            int endingPosition =  execute_a_move(x,current_moveR, joueur);
            x = capture(x, endingPosition, joueur);
            int val = alphabeta(x, (joueur), depth, -INFINITY, INFINITY);
            values.insert(std::make_pair(current_moveR.toString(), val));
        }
        if(is_a_move_legal(initialBoard, current_moveB, joueur)){
            Board x;
            int endingPosition =  execute_a_move(x,current_moveB, joueur);
            x = capture(x, endingPosition, joueur);
            int val = alphabeta(x,  (joueur), depth, -INFINITY, INFINITY);
            values.insert(std::make_pair(current_moveB.toString(), val));
        }
    }

    if (joueur == 0){
        int max = -INFINITY;
        string maxStr;
        printf("\naffichage des valeurs de chaque coups");
        for(const auto& elem : values) {
            std::cout << elem.first << " || " << elem.second << "\n";
            if (elem.second > max) {
                max = elem.second;
                maxStr = elem.first;
            }
        }
        Move res = parse_a_move(maxStr);
        res.starting_hole++;
        return res;

    } else {
        int min = INFINITY;
        string minStr;
        printf("\naffichage des valeurs de chaque coups");
        for(const auto& elem : values) {
            std::cout << elem.first << " || " << elem.second << "\n";
            if (elem.second < min) {
                min = elem.second;
                minStr = elem.first;
            }
        }
        Move res = parse_a_move(minStr);
        res.starting_hole++;
        return res;

    }

}

