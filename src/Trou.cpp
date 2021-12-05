#include <iostream>
#include <cstdlib>  
#include <sstream>

class Trou{
	public :
        //constructeurs
        Trou();

        //variables
		char graine_rouge;
        char graine_bleu;

        //fonctions
		void addRed();
        void addBlue();
        int empty_color(char);
        int empty_all();
        bool equals(Trou);
        std::string toString();
};

Trou::Trou(){
    graine_rouge = 2;
    graine_bleu = 2;
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

/**
 *  Vide un trou d'une couleur donnée
 *  Renvoit le nombre de graines vidées
 */ 
int Trou::empty_color(char color){
    int sum;
    if (color == 'B'){
        sum = this->graine_bleu;
        this->graine_bleu = 0;
        return sum;
    }else {
        sum = this->graine_bleu;
        this->graine_rouge = 0;
        return sum;
    }
}

/**
 *  Vide un trou de toutes ses graines
 *  Renvoit le nombre de graines vidées (sans distinction de couleur)
 */ 
int Trou::empty_all(){
    int sum = this->graine_bleu + this->graine_rouge;
    this->graine_bleu = 0;
    this->graine_rouge = 0;
    return sum;
}

/**
 * Compare un trou avec un autre (utile pour le testing)
 */ 
bool Trou::equals(Trou other_trou){
    return (this->graine_bleu == other_trou.graine_bleu) && (this->graine_rouge == other_trou.graine_rouge);
}

std::string Trou::toString() {
    std::ostringstream strout;
    strout<< "(\033[1;31mR : " << +this->graine_rouge << "\033[0m|\033[1;34mB : " << +this->graine_bleu << "\033[0m)";
    return strout.str();
}

