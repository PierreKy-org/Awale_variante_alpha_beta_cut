class Move {

    public:           
        //Variables
        int starting_hole;
        char color;
        int gain = 0;
        //Constructeur
        Move(int , char );
        void printer();
        int getGain();
        void setGain(int);
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

int Move::getGain(){
    return this->gain;
}

void Move::setGain(int gain){
    this->gain = gain;
}