#include <iostream>
#include <cstdlib>  
#include <ctime>
#include <sstream>

class Trou{
	public :
		void addRed(char);
        void addBlue(char);
		char graine_rouge = 2;
        char graine_bleu = 2;
        std::string toString();
};

void Trou::addRed(char nb_red){
	this->graine_rouge += nb_red;

}

void Trou::addBlue(char nb_blue){
	this->graine_bleu += nb_blue;
}

std::string Trou::toString() {
    std::ostringstream strout;
    strout<< "(\033[1;31mR : " << +this->graine_rouge << "\033[0m|\033[1;34mB : " << +this->graine_bleu << "\033[0m)";
    return strout.str();
}



class Graine{
    public :
		bool graine_ = true; //TRUE ROUGE | FALSE BLEU

};


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
    Trou* cases[16] {new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou(),new Trou()};
    char gainJ1 = 0;
    char gainJ2 = 0;
    bool tour = true;
    bool ingame = true;

    srand((unsigned int)time(0)); //Modifie la liste pseudorandom par rapport à l'heure où le programme s'éxecute (si tu execute au meme moment alors on aura le meme resultat)

    //BOUCLE DE JEU 
    while(ingame){
        //Le joueur choisie une case
       /*  int v1 = rand() % 6;         
        int v2 = rand() % 6 + 6;     
        //UN tour sur 2 le joueur 1 joue    
        if(tour){
            gainJ1 += deplacementEtGain(cases,v1); // On ajoute le nomre de graine gagné au score du joueur 
            tour = false;
        }
        else{
            gainJ2 += deplacementEtGain(cases, v2); //On ajoute le nomre de graine gagné au score du joueur
            tour = true;
        } */
        //AFFICHAGE DU BOARD
        std::cout << "[ ";
        for(int i = 0; i < 16; i++){
            std::cout << cases[i]->toString() << ", ";
        }
        std::cout << "]" <<std::endl;
      /*   //LE JOUEUR 1 EST FINITO
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
 */
        }
    } 

