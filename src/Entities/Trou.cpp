#include <iostream>
#include <cstdlib>  
#include <sstream>

class Trou{
	public :
        //constructeurs
        Trou();

        //variables
		short graine_rouge;
        short graine_bleu;

        //fonctions
		void addRed();
        void addBlue();
        int empty_color(char);
        int empty_all();
        bool equals(Trou);
        bool isTakeable();
        std::string toString(int);
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

bool Trou::isTakeable(){
    int grainesTotal = this->graine_bleu + this->graine_rouge;
    return (grainesTotal == 2) || (grainesTotal == 3);
}

/**
 * Compare un trou avec un autre (utile pour le testing)
 */ 
bool Trou::equals(Trou other_trou){
    return (this->graine_bleu == other_trou.graine_bleu) && (this->graine_rouge == other_trou.graine_rouge);
}

std::string Trou::toString(int i) {
    std::ostringstream strout;
    if (i < 10){
        strout<< "0" <<  i;
    } else {
        strout<< i;

    }
    strout<< "(\033[1;31mR : " << +this->graine_rouge << "\033[0m|\033[1;34mB : " << +this->graine_bleu << "\033[0m)";
    return strout.str();
}

