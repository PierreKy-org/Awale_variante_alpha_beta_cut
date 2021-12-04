#include <sstream>

class Move {

    public:           
        //Variables
        int starting_hole;
        char color;

        //Functions
        Move(int starting_hole, char color);
};

/**
 * Constructeur
 */ 
Move::Move(int start, char col) {
    starting_hole = start;
    color = col;
}