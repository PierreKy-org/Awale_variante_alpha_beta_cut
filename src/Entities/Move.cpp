class Move {

    public:           
        //Variables
        int starting_hole;
        char color;

        //Constructeur
        Move(int , char );
        void printer();
};

/**
 * Constructeur
 */ 
Move::Move(int start, char col) {
    starting_hole = start;
    color = col;
}


void Move::printer(){
    std::cout << starting_hole << color << std::endl;
}