#include <iostream>
#include <cstdlib>  
#include <sstream>

class Trou{
	public :
		void addRed();
        void addBlue();
		char graine_rouge = 2;
        char graine_bleu = 2;
        std::string toString();
};

/**
 * On ne peut déposer qu'une graine par trou (d'où le += 1)
 */ 
void Trou::addRed(){
	this->graine_rouge += 1;
}

void Trou::addBlue(){
	this->graine_bleu += 1;
}

std::string Trou::toString() {
    std::ostringstream strout;
    strout<< "(\033[1;31mR : " << +this->graine_rouge << "\033[0m|\033[1;34mB : " << +this->graine_bleu << "\033[0m)";
    return strout.str();
}
