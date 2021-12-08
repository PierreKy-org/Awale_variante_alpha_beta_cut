// A simple C++ program to find
// maximum score that
// maximizing player can get.
#include<bits/stdc++.h>
#include "Rules/CapturingRules.cpp"
using namespace std;



Move* allMoves(Board board, int joueur){
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
    return listMoves;
}

int evaluation(Board board){
    return board.gainJ1-board.gainJ2;
}

 int valeurMinMax(Board board, int joueur, int prof, int profMax){
    // ordi_joue est un booleen qui est vrai si l'ordi joue
    int tab_valeurs[8];
    Board pos_next; // En C on crée dans la pile = TRES rapide

    /* if (positionFinale(pos_courante, ordi_joue,prof)){
            // code à écrire
        
            // on retourne VALMAX (=48) si l'ordi gagne et -48 si l'ordi perd  et 0 si nul
    } */
    if (prof == profMax) {
            return evaluation(board);
            // dans un premier temps l'évaluation sera la
            // différence du nb de pions pris
    }
    Move* moves = allMoves(board, joueur);
    for(int i=0;i<8;i++){
            // on joue le coup i
            // ecrire la fn coupValide(pos_courante,ordi_joue,i)
            // elle teste si on peut prendre les pions dans la
            // case i et les jouer (si pas de pion alors elle retourne invalide). La position de départ
            // est pos_courante
            Move currentMove = moves[i];
            if (is_a_move_legal(board,currentMove,joueur)){
                    // ecrire la fn :
                int casse =  execute_a_move(board,moves[i], 0);
                capture(board,casse,0);
                // on joue le coup i a partir de la position
                // pos_courante et on met le résultat
                // dans pos_next
                //jouerCoup(&pos_next,pos_courante,joueur,i);
                // pos_next devient la position courante, et on change le joueur
                tab_valeurs[i]=valeurMinMax(board, joueur%2,prof+1,profMax);
            }
            else {
                if (joueur==0) tab_valeurs[i]=-100;
                else tab_valeurs[i]=+100;
            }
    }
    int res;
    if (joueur){
            res = 5;
    } else {
            res = 5;
    }
    return res;
}


int main(){

    Board board ;
    int joueur = 0;
    int prof = 1;
    valeurMinMax(board,joueur,0,1);
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
