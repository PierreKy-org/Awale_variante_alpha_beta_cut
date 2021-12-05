#include <sstream>

class Move {

    public:           
        //Variables
        int starting_hole;
        char color;

        //Constructeur
        Move(int , char );
};

/**
 * Constructeur
 */ 
Move::Move(int start, char col) {
    starting_hole = start;
    color = col;
}