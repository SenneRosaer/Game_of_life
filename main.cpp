#include <iostream>
#include "functional"
#include "Game.hpp"


int main() {
    try{

        std::function<bool (bool,int)> ruleLambda = [](bool alive, int neighbour){
            if(alive){
                if(neighbour == 2 or neighbour == 3){
                    return true;
                } else if (neighbour < 2){
                    return false;
                } else if (neighbour > 3){
                    return false;
                }
            } else {
                if(neighbour == 3){
                    return true;
                }
            }

            return false;
        };

        Game<15,30> game(100,ruleLambda);



        game(7,14);
        game(7,15);
        game(7,16);
        game(7,17);
        game(7,18);

        game.evolve();

    } catch(...){

    }
    return 0;
}