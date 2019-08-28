//
// Created by sennerosaer on 8/28/19.
//

#ifndef GAME_OF_LIFE_GAME_HPP
#define GAME_OF_LIFE_GAME_HPP

#include "memory"
#include "iostream"
#include "Cell.h"
#include "functional"
#include "Grid.hpp"
#include "vector"


template <size_t ROW, size_t COL>
class Game{
private:
    int m_iterations;
    std::function<bool(bool, int)> m_rules;
    Grid<ROW,COL> m_grid;

    void evaluate_grid();

    std::vector<std::pair<int,int>> m_cells_to_create = {};
    std::vector<std::pair<int,int>> m_cells_to_delete = {};


public:
    Game(int iterations,const std::function<bool (bool,int)>& f);

    void evolve();

    void operator()(int a,int b);

};

template <size_t ROW, size_t COL>
Game<ROW,COL>::Game(int iterations, const std::function<bool(bool, int)>& f) {
    m_iterations = iterations;
    m_rules = f;
}

template <size_t ROW, size_t COL>
void Game<ROW,COL>::evolve() {
    for (int i = 0; i < m_iterations; ++i) {
        m_grid.print();
        evaluate_grid();
        for(auto& item : m_cells_to_create){
            m_grid.gridObject(item.first,item.second,std::make_shared<AliveCell>() );
        }
        for(auto& item : m_cells_to_delete){
            m_grid.gridObject(item.first,item.second,std::make_shared<DeadCell>() );
        }

        m_cells_to_delete.clear();
        m_cells_to_create.clear();

    }
}


template <size_t ROW, size_t COL>
void Game<ROW,COL>::operator()(int a, int b) {
    if(a < 0 or a > ROW or b < 0 or b > COL){
        throw std::out_of_range("Given locations are out of bound");
    }
    m_grid.gridObject(a,b,std::make_shared<AliveCell>());
}


template <size_t ROW, size_t COL>
void Game<ROW,COL>::evaluate_grid() {
    for (size_t i = 0; i < ROW; i++) {
        for (size_t j = 0; j < COL; j++) {
            int neighbour = 0;

            for(size_t x = i-1;x <= i+1; x++){
                for(size_t y = j-1;y <= j+1; y++) {
                    if(x >= 0 and x < ROW and y >= 0 and y <COL ){
                        if( x != i or y != j ) {
                            if (m_grid.getCell(x, y)->Alive()) {
                                neighbour++;
                            }
                        }
                    }
                }
            }

            bool current_cell_status = m_grid.getCell(i,j)->Alive();
            if(current_cell_status and m_rules(current_cell_status,neighbour)){

            } else if(current_cell_status and !m_rules(current_cell_status,neighbour)){
                m_cells_to_delete.push_back({i,j});
            } else if(!current_cell_status and m_rules(current_cell_status,neighbour)){
                m_cells_to_create.push_back({i,j});
            }

        }
    }
}
#endif //GAME_OF_LIFE_GAME_HPP
