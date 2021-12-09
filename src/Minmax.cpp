// A simple C++ program to find
// maximum score that
// maximizing player can get.
#include<bits/stdc++.h>
#include<iterator>
#include <tuple>
#include "Rules/CapturingRules.cpp"
using namespace std;



std::tuple<Move*, int> allMoves(Board board, int joueur){
    int i = 0;
    int size = 16; //
    Move *listMoves = (Move*)malloc(sizeof(Move)*size);
    int cpt = 0;
    //TODO OPTIMISATION PASSER PAR 1 TROU SUR 2 
    for(i = 0; i < 16; i++){
        Move current_moveR(i,'R');
        Move current_moveB(i,'B');
        if(is_a_move_legal(board, current_moveR, joueur)){
            listMoves[cpt] = current_moveR;
            cpt++;
        }
        
        if(is_a_move_legal(board, current_moveB, joueur)){
            listMoves[cpt] = current_moveB;
            cpt++;
        }
    }
    //Si il y a moins de coup alors on realloue les coups dans une autre liste de bonne taille
    Move *listMovesFinal = (Move*)malloc(sizeof(Move)*cpt);
    for(int i = 0; i < cpt;i++){
        listMovesFinal[i] = listMoves[i];
    }
    free(listMoves);
    return {listMovesFinal,cpt};
}

int evaluation(Board board){
    return board.gainJ1-board.gainJ2;
}


 int valeurMinMax(Board board, int joueur, int prof, int profMax){
    // ordi_joue est un booleen qui est vrai si l'ordi joue
    Board b;
     // En C on crée dans la pile = TRES rapide

    /* if (positionFinale(pos_courante, ordi_joue,prof)){
            // code à écrire
        
            // on retourne VALMAX (=48) si l'ordi gagne et -48 si l'ordi perd  et 0 si nul
    } */
    if (prof == profMax) {
            std::cout << "evalution en cours : "<< evaluation(board) << std::endl;
            return evaluation(board);
            // dans un premier temps l'évaluation sera la
            // différence du nb de pions pris
    }
    auto [moves, size] = allMoves(board, joueur);
     int tab_valeurs[size];
    int cpt = 1;
    for(int i=0;i<size;i++){
        std::cout << "fils numéro " << cpt << std::endl;
        b.copy(board);
        
        // on joue le coup i
        // ecrire la fn coupValide(pos_courante,ordi_joue,i)
        // elle teste si on peut prendre les pions dans la
        // case i et les jouer (si pas de pion alors elle retourne invalide). La position de départ
        // est pos_courante
        Move currentMove = moves[i];
        if (is_a_move_legal(b,currentMove,joueur)){
                // ecrire la fn :
                
            int casse =  execute_a_move(b,moves[i], 0);
            b = capture(b,casse,0);
            // on joue le coup i a partir de la position
            // pos_courante et on met le résultat
            // dans pos_next
            //jouerCoup(&pos_next,pos_courante,joueur,i);
            // pos_next devient la position courante, et on change le joueur
            tab_valeurs[i]=valeurMinMax(b, joueur%2,prof+1,profMax);
        }
        else {
            if (joueur==0) tab_valeurs[i]=-100;
            else tab_valeurs[i]=+100;
        }
        cpt++;
    }
    int res;
    if (joueur){
            for(int i=0;i<size;i++){
                std::cout << tab_valeurs[i] << std::endl;
            }
            int* x = std::max_element(tab_valeurs, tab_valeurs+8);
            std::cout << "LE MAXIMUM EST : " << *x << std::endl;    
            res = *x;
            } else {
            for(int i=0;i<size;i++){
                std::cout << tab_valeurs[i] << std::endl;
            }
            int* x = std::min_element(tab_valeurs, tab_valeurs+8);
            std::cout << "LE MINIMUM EST : " << *x << std::endl;
            res = *x;
    }
    return res;
}


int main(){

    Board board;
    std::cout << valeurMinMax(board,0,0,6) << std::endl;
    return 0;
}


/* int x(Board board){
    Board *listBoards = (Board*)malloc(sizeof(Board)*16);
    Move* moves = allMoves(board);
    for(int i = 0; i < 16; i++){
        Board board;
        printf("%d : %d,%c \n", i, moves[i].starting_hole, moves[i].color);

        int casse =  execute_a_move(board,moves[i], 0);
        capture(board,casse,0)
        listBoards[i] = board;
        int i = x(board);


    }
    free(moves);
    return board.gainJ1;
} */
