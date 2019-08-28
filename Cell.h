//
// Created by sennerosaer on 8/28/19.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

#include "iostream"

class Cell {
public:
    virtual bool Alive() = 0;

    friend std::ostream& operator<<(std::ostream& out,const Cell& cell);

private:
    virtual std::string getStringRep() const = 0;
};



class AliveCell : public Cell{
public:
    bool Alive() override;

private:
    std::string getStringRep() const override;

};


class DeadCell : public  Cell{
public:
    bool Alive() override;


private:
    std::string getStringRep() const override;


};

#endif //GAME_OF_LIFE_CELL_H
