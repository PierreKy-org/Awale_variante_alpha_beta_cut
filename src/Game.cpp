#include <sstream>
#include "Rules/CapturingRules.cpp"



int main(){
    Board board;
    int currentPlayer = 0;
    int endingPosition;

    printf("LA CAPTURE NE FONCTIONNE PAS DANS LE MAIN, IL FAUT VOIR LA VALEUR DE ENDING POSITION");
    while (board.ingame){
        Move currentMove = parse_a_move();

        if (is_a_move_legal(board, currentMove, currentPlayer)){
            endingPosition = execute_a_move(board, currentMove, currentPlayer);
            board = capture(board, endingPosition, currentPlayer);
            board.ingame = !(is_it_the_end_of_the_game(board));
            currentPlayer = (currentPlayer + 1)%2;
            printf("----- The board : ------\n");
            board.printer();
            printf("\ngainJ1 = %d\ngainJ2 = %d", board.gainJ1, board.gainJ2);
        }
        //On reste dans la boucle (sur le même joueur)
        else{
            printf("Illegal Move, select another\n");
        }

    }

    printf("it's the end of the world as we know it (and i feel fine)");
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
