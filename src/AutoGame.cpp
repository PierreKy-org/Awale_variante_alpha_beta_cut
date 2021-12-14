#include <sstream>
#include "MinMax.cpp"

const int WE_ARE_PLAYER = 0; //Définit quel joueur on est dans la game (0 ou 1);
const int PROFONDEUR = 5;


void print_turn(int currentPlayer){
    if (currentPlayer == 0){
        printf("---- Au tour du joueur IMPAIR\n");
    } else {
        printf("---- Au tour du joueur PAIR\n");
    }
}

int main(){
    Board board;
    bool illegal_flag = false;
    int currentPlayer = 0;
    int endingPosition;
    
    printf("==================== Début de la partie : \n");
    board.printer();

    while (board.ingame){
        illegal_flag = false; //On reset le flag pour pouvoir essayer un autre coup
        print_turn(currentPlayer);

        if (currentPlayer == WE_ARE_PLAYER){
            printf("Calcul en cours ...\n");
            Move ourMove = playAMove(board, currentPlayer, PROFONDEUR);
            printf("On joue le coup : %d%c\n", ourMove.starting_hole, ourMove.color);
            //ourMove.starting_hole--;
            if(is_a_move_legal(board, ourMove, currentPlayer)){
                endingPosition = execute_a_move(board, ourMove, currentPlayer);
                board = capture(board, endingPosition, currentPlayer);
                printf("... Nombre de positions calculées %d\n",total);
                total = 0;

            } else {
                std::cout << "Coup illegal\n" << std::endl;
                illegal_flag = true;
            }

        } else {

            //On joue le coup de l'adversaire
            printf("Calcul en cours ...\n");
            Move theirMove = playAMove(board, currentPlayer, PROFONDEUR);
            printf("On joue le coup : %d%c\n", theirMove.starting_hole, theirMove.color);
            //ourMove.starting_hole--;
            if(is_a_move_legal(board, theirMove, currentPlayer)){
                endingPosition = execute_a_move(board, theirMove, currentPlayer);
                board = capture(board, endingPosition, currentPlayer);
                printf("... Nombre de positions calculées %d\n",total);
                total = 0;

            } else {
                std::cout << "Coup illegal\n" << std::endl;
                illegal_flag = true;
            }


            if (is_a_move_legal(board, theirMove, currentPlayer)){
                endingPosition = execute_a_move(board, theirMove, currentPlayer);
                board = capture(board, endingPosition, currentPlayer);
            } else {
                printf("Coup illegal !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                illegal_flag = true;
                    
            }
        }
        //Si le coup joué était illegal, on n'actualise pas la game
        if (!illegal_flag){
            printf("Etat du board après le coup\n");
            board.printer();
            printf("\ngainJ1 = %d\ngainJ2 = %d\n", board.gainJ1, board.gainJ2);
            currentPlayer = (currentPlayer + 1)%2;
            board.ingame = !(is_it_the_end_of_the_game(board));
        }
    }
    printf("Fin de la partie");
}
