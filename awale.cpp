#include <iostream>
#include <cstdlib>  
#include <ctime>


int deplacementEtGain(int* cases, int nb){
    int temp = cases[nb];
    cases[nb] = 0; // On remplace la case par 0
    int acc = 1;
    int gain = 0;
    while(acc <= temp){ //On met une graine dans chaque prochain trou 
        cases[(nb+acc)%12] += 1;
        if(acc == temp){  //On vérifie si le joueur gagne des graines ou pas 
            bool encore = true;
            int acc2 = acc;
            while(encore){
                if(cases[(nb+acc2)%12] == 2 || cases[(nb+acc2)%12] == 3){
                    gain += cases[(nb+acc2)%12];
                    std::cout << gain <<  std::endl;
                    cases[(nb+acc2)%12] = 0; 
                    acc2 -= 1;
                }
                else{
                    encore = false;
                }
            }
        }
        acc++;
    }
    return gain; //On renvoi le nombre de graine gagné
}

int main(){
    //INITIALISATION
    int cases[16] {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
    int gainJ1 = 0;
    int gainJ2 = 0;
    bool tour = true;
    bool ingame = true;

    srand((unsigned int)time(0)); //Modifie la liste pseudorandom par rapport à l'heure où le programme s'éxecute (si tu execute au meme moment alors on aura le meme resultat)

    //BOUCLE DE JEU 
    while(ingame){
        //Le joueur choisie une case
        int v1 = rand() % 6;         
        int v2 = rand() % 6 + 6;     
        //UN tour sur 2 le joueur 1 joue    
        if(tour){
            gainJ1 += deplacementEtGain(cases,v1); // On ajoute le nomre de graine gagné au score du joueur 
            tour = false;
        }
        else{
            gainJ2 += deplacementEtGain(cases, v2); //On ajoute le nomre de graine gagné au score du joueur
            tour = true;
        }
        //AFFICHAGE DU BOARD
        std::cout << "[ " << cases[0] << " " << cases[1]  << " " << cases[2]  << " " << cases[3]
          << " " << cases[4]  << " " << cases[5]  << " " << cases[6]  <<" " << cases[7]  <<" " << cases[8] 
           <<" " << cases[9]  <<" " << cases[10]  <<" " << cases[11]  <<" ]" << std::endl;

        //LE JOUEUR 1 EST FINITO
        if (cases[0] == 0 && cases[1] == 0 && cases[2] == 0 && cases[3] == 0 && cases[4] == 0 && cases[5] == 0){
            std::cout << "le joueur 1 est affamé, le joueur 2 a gagné" << std::endl;
            std::cout << gainJ1 << " | " << gainJ2 << std::endl;
            ingame = false;
        }
        //LE JOUEUR 2 EST FINITO
        else if(cases[6] == 0 && cases[7] == 0 && cases[8] == 0 && cases[9] == 0 && cases[10] == 0 && cases[11] == 0){
            std::cout << "le joueur 2 est affamé, le joueur 1 a gagné" << std::endl;
            std::cout << gainJ1 << " | " << gainJ2 << std::endl;

            ingame = false;

        }
    }

}