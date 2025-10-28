namespace targets {

class Alien{
    public:
        Alien(int x, int y): x_coordinate(x), y_coordinate(y) {}
        int get_health(){
            return this->health;
        }
        bool hit(){
            if(this->health > 0){this->health -= 1;}
            return true;
        }
        bool is_alive(){
            return (this->health > 0)? true : false;
        }
        bool teleport(int x_new, int y_new){
            this->x_coordinate = x_new;
            this->y_coordinate = y_new;
            return true;
        }
        bool collision_detection(Alien otherAlien){
            return (
                this->x_coordinate == otherAlien.x_coordinate && 
                this->y_coordinate == otherAlien.y_coordinate
            )? true : false;
        }
        int x_coordinate{0};
        int y_coordinate{0};
    private:

        int health{3};
};


}  // namespace targets
