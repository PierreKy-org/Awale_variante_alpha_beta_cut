#include <iostream>
#include <cstdlib>  
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
