//
// Created by sennerosaer on 8/28/19.
//

#include "Cell.h"

bool AliveCell::Alive() {
    return true;
}

std::string AliveCell::getStringRep() const {
    return "*";
}

bool DeadCell::Alive() {
    return false;
}

std::string DeadCell::getStringRep() const {
    return ".";
}

std::ostream &operator<<(std::ostream &out, const Cell &cell) {
        out << cell.getStringRep();
        return out;
}
