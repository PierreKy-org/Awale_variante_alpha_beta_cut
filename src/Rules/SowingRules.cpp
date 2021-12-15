#include <iostream>
#include <cstdlib>  
#include <sstream>
#include <string>
#include "../Entities/Board.cpp"
using namespace std;


/*Renvois un objet Move, si le move commence à -1 il est cassé"*/
//Default input permet de tester et aussi de jouer sans attendre les inputs du joueur
Move parse_a_move(string defaultInput=""){
    string input;

    if(defaultInput == ""){
        cout << "\nEnter a move : ";
        cin >> input; 
    } else {
        input = defaultInput;
    }

    char color = input[input.length() -1];
    input.erase(input.length() -1, 1);
    int start = stoi(input)-1;

    Move move = Move(start, color);
    if ((color != 'B') && (color != 'R')){
        //Move errone
        move.starting_hole = -1;
        move.color = '0';
    }
    return move;
}

/**
 * On est sûrs que la couleur du move est correcte après le parsing
 * Un move faux est un move qui commence à une case inexistante
 * Un move qui commence dans la case de l'autre joueur (j1 -> pair, j2-> impair)
 * joueur 1 vaut 0
 * joueur 2 vaut 1
 * C'est plus simple pour le modulo
 * Un move qui demande des graines d'une couleur impossible
 * 
 */ 
bool is_a_move_legal(Board board, Move move, int joueur){
    int startingHole = move.starting_hole;
    //Vérifie que la case existe
    if ((startingHole < 0)
        || (startingHole > 15)){
            return false;
        }
    //Vérifie que la case de départ appartienne bien au joueur
    if (startingHole%2 != joueur){
        return false;
    }

    //Vérifie que la case contienne des graines
    if (move.color == 'B'){
        return (board.cases[startingHole].graine_bleu > 0 );
    }else{
        return (board.cases[startingHole].graine_rouge > 0);
    }

}

/**
 * règle d'essaimage pour les graines rouges
 */ 
int sowing_red(Board* board, Move move, int joueur){
    int startingHole = move.starting_hole;
    int totalDeGraines = board->cases[startingHole].graine_rouge;
    int caseActuelle;

    board->cases[startingHole].empty_color(move.color); //Enlève les graines de la case de départ 
    int compteur = 1;//Commence à un pour mettre dans la case suivante directement
    while (totalDeGraines > 0){
        caseActuelle = (startingHole + compteur)%16;
        //vérifie qu'on met les graines dans les bonnes cases
        //C'est à dire : les cases de l'adversaire et surtout pas les notres
        if (caseActuelle == startingHole){
            //Skip si on remet une graine dans la case de départ
            compteur++;
            continue;
        }
        board->cases[caseActuelle].addRed();
        totalDeGraines--;

        compteur++;
    }
    return caseActuelle; //renvoit la case actuelle pour savoir d'où on repart lors de la capture
}
/**
 * règle d'essaimage pour les graines bleues
 * On ne vérifie pas si l'on remet dans la case de départ car les
 * graines bleues ne peuvent pas être mises dans la case du joueur qui les joue
 */ 
int sowing_blue(Board* board, Move move, int joueur){
    int startingHole = move.starting_hole;
    int totalDeGraines = board->cases[startingHole].graine_bleu;
    int caseActuelle;

    board->cases[startingHole].empty_color(move.color); //Enlève les graines de la case de départ 

    int compteur = 1;//Commence à un pour mettre dans la case suivante directement
    while (totalDeGraines > 0){
        caseActuelle = (startingHole + compteur)%16;

        //vérifie qu'on met les graines dans les bonnes cases
        //C'est à dire : les cases de l'adversaire et surtout pas les notres
        if (caseActuelle % 2 != joueur){
            board->cases[caseActuelle].addBlue();
            totalDeGraines--;
        }
        compteur++;
    }
    return caseActuelle;
}

/**
 * Joue un coup sur le board. 
 * La fonction ne vérifie pas si le coup est jouable ou non elle le joue juste.
 * (il faut donc s'assurer que c'est jouable avant de le jouer)
 */ 
int execute_a_move(Board* board, Move move, int joueur){
    int caseDeFin;
    if (move.color == 'B'){
        caseDeFin = sowing_blue(board, move, joueur);
    }else{
        caseDeFin = sowing_red(board, move, joueur);
    }
  //  printf("Case de fin : %d\n", caseDeFin);
    return caseDeFin;
}
