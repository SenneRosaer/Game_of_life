//
// Created by sennerosaer on 8/28/19.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

#include "iostream"

class Cell {
public:
    /**
     * Pure virtual function to return cell status
     * @return
     */
    virtual bool Alive() = 0;

    /**
     * << operator overloader
     * @param out
     * @param cell
     * @return
     */
    friend std::ostream& operator<<(std::ostream& out,const Cell& cell);

private:
    /**
     * Pure virtual function to return string representation of a cell
     * @return
     */
    virtual std::string getStringRep() const = 0;
};



class AliveCell : public Cell{
public:
    /**
     * Always returns true
     * @return
     */
    bool Alive() override;

private:
    /**
     * Returns *
     * @return
     */
    std::string getStringRep() const override;

};


class DeadCell : public  Cell{
public:
    /**
     * Always returns false
     * @return
     */
    bool Alive() override;


private:
    /**
     * Returns .
     * @return
     */
    std::string getStringRep() const override;


};

#endif //GAME_OF_LIFE_CELL_H
