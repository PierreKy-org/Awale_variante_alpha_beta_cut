// A simple C++ program to find
// maximum score that
// maximizing player can get.
#include<bits/stdc++.h>
#include<iterator>
#include <tuple>
#include <algorithm>
#include "Rules/CapturingRules.cpp"

using namespace std;

bool compare(Move a, Move b){

    return a.getGain() <  b.getGain();
}


std::tuple<Move*, int> allMoves(Board board, int joueur){
    int size = 16; //
    Move *listMoves = (Move*)malloc(sizeof(Move)*size);
    int cpt = 0;
    //TODO OPTIMISATION PASSER PAR 1 TROU SUR 2 
    for(int i = joueur; i < 16; i+=2){
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


Move valeurMinMax(Board board, int joueur, int prof, int profMax, Move move){
    // ordi_joue est un booleen qui est vrai si l'ordi joue
    Board b;
     // En C on crée dans la pile = TRES rapide
    /* if (positionFinale(pos_courante, ordi_joue,prof)){
            // code à écrire
        
            // on retourne VALMAX (=48) si l'ordi gagne et -48 si l'ordi perd  et 0 si nul
    } */
    if (prof == profMax) {
            move.setGain(evaluation(board));
            return move;
    }

    auto [moves, size] = allMoves(board, joueur);
     Move *tab_valeurs = (Move*)malloc(sizeof(Move)*size);

    int cpt = 1;
    for(int i=0;i<size;i++){
        //std::cout << "fils numéro " << cpt << std::endl;
 
        b.copy(board);
        // on joue le coup i
        // ecrire la fn coupValide(pos_courante,ordi_joue,i)
        // elle teste si on peut prendre les pions dans la
        // case i et les jouer (si pas de pion alors elle retourne invalide). La position de départ
        // est pos_courante
        Move currentMove = moves[i];
        // ecrire la fn :
        int casse =  execute_a_move(b,moves[i], joueur);
        b = capture(b,casse, joueur);
        // on joue le coup i a partir de la position
        // pos_courante et on met le résultat
        // dans pos_next
        //jouerCoup(&pos_next,pos_courante,joueur,i);
        // pos_next devient la position courante, et on change le joueur
        tab_valeurs[i]=valeurMinMax(b, (joueur+1)%2,prof+1,profMax, currentMove);
        cpt++;
        
    }
    Move res(19,'Y');
    if (joueur == 0) {
            /*  for(int i=0;i<size;i++){
                std::cout << tab_valeurs[i] << std::endl;
            }  */
            Move* x = std::max_element(tab_valeurs, tab_valeurs+size, compare);
           // std::cout << "LE MAXIMUM EST : " << *x << " | " << std::distance(tab_valeurs, x) << std::endl;    
            res = *x;
    } 
    else {
           /*   for(int i=0;i<size;i++){
                std::cout << tab_valeurs[i] << std::endl;
            } */
            Move* x = std::min_element(tab_valeurs, tab_valeurs+size, compare); 
           // std::cout << "LE MINIMUM EST : " << *x << " | " << std::distance(tab_valeurs, x) << std::endl;
            res = *x;
    }
    return res;
}

