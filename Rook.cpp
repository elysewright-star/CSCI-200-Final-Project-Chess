#include "Rook.h"
#include <iostream>

Rook::Rook() {

}
void Rook::setColor(int color) {
    _color = color;

}
int Rook::getColor() {
    return _color;

}
void Rook::setX(char x) {
    _x = x;

}
char Rook::getX() {
    return _x;

}
void Rook::setY(int y) {
    _y = y;

}
int Rook::getY() {
    return _y;

}
void Rook::setAlive(bool alive) {
    _alive = alive;
}
bool Rook::getAlive() {
    return _alive;

}
std::vector<std::pair<char, int>> Rook::getMoves(King ourKing, Rook r1, Rook r2, Rook r3) {
    std::vector<std::pair<char, int>> validMoves;
    for (int i = -7; i < 8; i++) {
        if (_x + i == ('a'-1) || _x + i == ('h'+1)) {
            continue;
        }
        if (_y + i || _y + i == 9) {
            continue;
        }
        //ourKing
        if (_x + i == ourKing.getX() && _y + i == ourKing.getY()) {
            continue;
        }
        if (_x + i < ourKing.getX() && _y + i == ourKing.getY()) {
            if (_x + i > ourKing.getX()) {
                continue;
            }
        }
        if (_x + i > ourKing.getX() && _y + i == ourKing.getY()) {
            if (_x + i < ourKing.getX()) {
                continue;
            }
        }
        if (_x + i == ourKing.getX() && _y + i > ourKing.getY()) {
            if (_y + i < ourKing.getY()) {
                continue;
            }
        }
        if (_x + i == ourKing.getX() && _y + i < ourKing.getY()) {
            if (_y + i > ourKing.getY()) {
                continue;
            }
        }

        //r1    
        if (r1.getAlive() && _x + i == r1.getX() && _y + i == r1.getY()) {
            continue;
        }
        if (_x + i < r1.getX() && _y + i == r1.getY()) {
            if (_x + i > r1.getX()) {
                continue;
            }
        }
        if (_x + i > r1.getX() && _y + i == r1.getY()) {
            if (_x + i < r1.getX()) {
                continue;
            }
        }
        if (_x + i == r1.getX() && _y + i > r1.getY()) {
            if (_y + i < r1.getY()) {
                continue;
            }
        }
        if (_x + i == r1.getX() && _y + i < r1.getY()) {
            if (_y + i > r1.getY()) {
                continue;
            }
        } 
        //r2
        if (r2.getAlive() && _x + i == r2.getX() && _y + i == r2.getY()) {
            continue;
        }
        if (r2.getAlive() && _x + i == r2.getX() && _y + i == r2.getY()) {
            continue;
        }
        if (_x + i < r2.getX() && _y + i == r2.getY()) {
            if (_x + i > r2.getX()) {
                continue;
            }
        }
        if (_x + i > r2.getX() && _y + i == r2.getY()) {
            if (_x + i < r2.getX()) {
                continue;
            }
        }
        if (_x + i == r2.getX() && _y + i > r2.getY()) {
            if (_y + i < r2.getY()) {
                continue;
            }
        }
        if (_x + i == r2.getX() && _y + i < r2.getY()) {
            if (_y + i > r2.getY()) {
                continue;
            }
        }
        //r3
        if (r3.getAlive() && _x + i == r3.getX() && _y + i == r3.getY()) {
            continue;
        }
                if (r3.getAlive() && _x + i == r3.getX() && _y + i == r3.getY()) {
            continue;
        }
        if (_x + i < r3.getX() && _y + i == r3.getY()) {
            if (_x + i > r3.getX()) {
                continue;
            }
        }
        if (_x + i > r3.getX() && _y + i == r3.getY()) {
            if (_x + i < r3.getX()) {
                continue;
            }
        }
        if (_x + i == r3.getX() && _y + i > r3.getY()) {
            if (_y + i < r3.getY()) {
                continue;
            }
        }
        if (_x + i == r3.getX() && _y + i < r3.getY()) {
            if (_y + i > r3.getY()) {
                continue;
            }
        }
        validMoves.push_back(std::make_pair(_x + i, _y + i));
    }
    return validMoves;    
}
bool Rook::checkingKing(King otherKing, King ourKing, Rook r1, Rook r2) {
    if (otherKing.getX() == _x) {
        // if our king in the way
        if (!(ourKing.getX() == _x && ((ourKing.getX() < otherKing.getX() && ourKing.getX() > _x)
            || (ourKing.getX() > otherKing.getX() && ourKing.getX() < _x)))) {
            return true;
        }
        //if other color rook 2 in the way
        if (r2.getAlive() && !(r2.getX() == _x && ((r2.getX() < otherKing.getX() && r2.getX() > _x)
            || (r2.getX() > otherKing.getX() && r2.getX() < _x)))) {
            return true;
        }
        //if other color rook 1 in the way
        if (r1.getAlive() && !(r1.getX() == _x && ((r1.getX() < otherKing.getX() && r1.getX() > _x)
            || (r1.getX() > otherKing.getX() && r1.getX() < _x)))) {
            return true;
        }                    
    }
    if (otherKing.getY() == _y) {
        // if our king in the way
        if (!(ourKing.getY() == _y && ((ourKing.getY() < otherKing.getY()
            && ourKing.getY() > _x) || (ourKing.getY() > otherKing.getY() && ourKing.getY() < _y)))) {
            return true;
        }
        //if other color 2 in the way
        if (r2.getAlive() && !(r2.getY() == _y && ((r2.getY() < otherKing.getY() && r2.getY() > _y)
            || (r2.getY() > otherKing.getY() && r2.getY() < _y)))) {
                return true;
        }
        //if other color rook 1 in the way
        if (r1.getAlive() && !(r1.getY() == _y && ((r1.getY() < otherKing.getY() && r1.getY() > _y)
            || (r1.getY() > otherKing.getY() && r1.getY() < _y)))) {
            return true;
        }    
    }
    return false;
}
