#include <iostream>
#include <cstdlib>  
#include <sstream>

class Trou{
	public :
        //constructeurs
        Trou();
        Trou(int, int);

        //variables
		char graine_rouge;
        char graine_bleu;

        //fonctions
		void addRed();
        void addBlue();
        void empty(char);
        std::string toString();
};

Trou::Trou(){
    char graine_rouge = 2;
    char graine_bleu = 2;
}

Trou::Trou(int nbRouge, int nbBleu){
    char graine_rouge = nbRouge;
    char graine_bleu = nbBleu;
}


/**
 * On ne peut déposer qu'une graine par trou (d'où le += 1)
 */ 
void Trou::addRed(){
	this->graine_rouge += 1;
}

void Trou::addBlue(){
	this->graine_bleu += 1;
}

void Trou::empty(char color){
    if (color == 'B'){
        this->graine_bleu = 0;
    }else {
        this->graine_rouge = 0;
    }
}


std::string Trou::toString() {
    std::ostringstream strout;
    strout<< "(\033[1;31mR : " << +this->graine_rouge << "\033[0m|\033[1;34mB : " << +this->graine_bleu << "\033[0m)";
    return strout.str();
}
