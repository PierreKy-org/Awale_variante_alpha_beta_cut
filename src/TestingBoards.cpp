#include <sstream>
#include "Rules.cpp"

//Attention ça ve devenir terrible ? 
//C'est juste pour le testing.
//ça permet de voir si un board est illegal
//ça permet de comparer le board pour voir si le sowing marche bien
//Je déclare les trous à la main et je crée un board avec les trous

/**
 * Board illegal, le trou 3 est vide et on essaye de piocher dedans
 */ 
Trou first_trou0(2,2);
Trou first_trou1(2,2);
Trou first_trou2(2,2);
Trou first_trou3(0,0);    //ici
Trou first_trou4(2,2);
Trou first_trou5(2,2);
Trou first_trou6(2,2);
Trou first_trou7(2,2);
Trou first_trou8(2,2);
Trou first_trou9(2,2);
Trou first_trou10(2,2);
Trou first_trou11(2,2);
Trou first_trou12(2,2);
Trou first_trou13(2,2);
Trou first_trou14(2,2);
Trou first_trou15(2,2);
Trou first_cases[] = {
    first_trou0, first_trou1, first_trou2, first_trou3,
    first_trou4, first_trou5, first_trou6, first_trou7,
    first_trou8, first_trou9, first_trou10, first_trou11,
    first_trou12, first_trou13, first_trou14, first_trou15
}; 

Board unLegalBoard01 = Board(first_cases);

