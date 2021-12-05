#include <sstream>
#include "Board.cpp"



int main(){
    Board board;
    board.printer();
}

/**
    srand((unsigned int)time(0)); //Modifie la liste pseudorandom par rapport à l'heure où le programme s'éxecute (si tu execute au meme moment alors on aura le meme resultat)

    //BOUCLE DE JEU 
    while(ingame){
        //Le joueur choisie une case
        int v1 = rand() % 6;         
        int v2 = rand() % 6 + 6;     
        //UN tour sur 2 le joueur 1 joue    
        if(tour){
            gainJ1 += deplacementEtGain(cases,v1); // On ajoute le nombre de graine gagné au score du joueur 
            tour = false;
        }
        else{
            gainJ2 += deplacementEtGain(cases, v2); //On ajoute le nombre de graine gagné au score du joueur
            tour = true;
        } 
    } 
*/
