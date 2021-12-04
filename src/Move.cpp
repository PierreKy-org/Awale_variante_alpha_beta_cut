#include <sstream>

class Move {

    public:           
        //Variables
        int starting_hole;
        int nbRed;
        int nbBlue;

        //Functions
        Move(int starting_hole, int nbRed, int nbBlue);
};

/**
 * Constructeur
 */ 
Move::Move(int start, int red, int blue) {
    starting_hole = start;
    nbRed = red;
    nbBlue = blue;
}