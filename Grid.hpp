//
// Created by sennerosaer on 8/28/19.
//

#ifndef GAME_OF_LIFE_GRID_HPP
#define GAME_OF_LIFE_GRID_HPP

#include "iostream"
#include "memory"
#include "Cell.h"

template<size_t ROW,size_t COL>
class Grid{
private:
    std::array<std::array<std::shared_ptr<Cell>,COL>,ROW> m_grid;

public:
    Grid();

    void gridObject(int rowIndex,int colIndex, const std::shared_ptr<Cell>& cell);

    std::shared_ptr<Cell> getCell(int row,int col);

    void print();
};


template  <size_t ROW,size_t COL>
Grid<ROW,COL>::Grid() {
    for(auto& row : m_grid){
        for(auto& item : row){
            item = std::make_shared<DeadCell>();
        }
    }
}


template  <size_t ROW,size_t COL>
void Grid<ROW,COL>::gridObject(int rowIndex,int colIndex, const std::shared_ptr<Cell>& cell){
    m_grid[rowIndex][colIndex] = cell;

}

template  <size_t ROW,size_t COL>
void Grid<ROW,COL>::print() {
    for(auto& row: m_grid){
        for(auto& elem: row){
            std::cout << *elem;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

template  <size_t ROW,size_t COL>
std::shared_ptr<Cell> Grid<ROW,COL>::getCell(int row, int col) {
    return m_grid[row][col];
}
#endif //GAME_OF_LIFE_GRID_HPP
