#include <sstream>
#include "MinMax.cpp"

const int WE_ARE_PLAYER = 0; //Définit quel joueur on est dans la game (0 ou 1);
const int PROFONDEUR = 6;


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
        if (board.currentPlayerIsStarving(currentPlayer)){
            board.ingame = false;
            break;
        }
        if (currentPlayer == WE_ARE_PLAYER){
            printf("Calcul en cours ...\n");

            using std::chrono::high_resolution_clock;
            using std::chrono::duration_cast;
            using std::chrono::duration;
            using std::chrono::milliseconds;

            //lancement du chrono
            auto t1 = high_resolution_clock::now();
            Move ourMove = playAMove(board, currentPlayer, PROFONDEUR);
            auto t2 = high_resolution_clock::now();

            printf("On joue le coup : %d%c\n", ourMove.starting_hole+1, ourMove.color);

            //fin du chrono
            auto ms_int = duration_cast<milliseconds>(t2 - t1);
            /* Getting number of milliseconds as a double. */
            duration<double, std::milli> ms_double = t2 - t1;
            std::cout << ms_int.count() << "ms\n";


            if(is_a_move_legal(board, ourMove, currentPlayer)){
                endingPosition = execute_a_move(&board, ourMove, currentPlayer);
                board = capture(board, endingPosition, currentPlayer);
                printf("... Nombre de positions calculées %d\n",total);
                total = 0;

            } else {
                std::cout << "Coup illegal\n" << std::endl;
                illegal_flag = true;
            }

        } else {

            printf("Calcul en cours ...\n");

            using std::chrono::high_resolution_clock;
            using std::chrono::duration_cast;
            using std::chrono::duration;
            using std::chrono::milliseconds;

            //lancement du chrono
            auto t1 = high_resolution_clock::now();
            Move ourMove = playAMove(board, currentPlayer, PROFONDEUR);
            auto t2 = high_resolution_clock::now();

            printf("On joue le coup : %d%c\n", ourMove.starting_hole+1, ourMove.color);

            //fin du chrono
            auto ms_int = duration_cast<milliseconds>(t2 - t1);
            /* Getting number of milliseconds as a double. */
            duration<double, std::milli> ms_double = t2 - t1;
            std::cout << ms_int.count() << "ms\n";


            if(is_a_move_legal(board, ourMove, currentPlayer)){
                endingPosition = execute_a_move(&board, ourMove, currentPlayer);
                board = capture(board, endingPosition, currentPlayer);
                printf("... Nombre de positions calculées %d\n",total);
                total = 0;

            } else {
                std::cout << "Coup illegal\n" << std::endl;
                illegal_flag = true;
            }
        }
    printf("Fin de la partie");
    }
}
    
