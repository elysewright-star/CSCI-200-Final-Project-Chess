#ifndef ROOK_H
#define ROOK_H
#include <vector>
#include <utility>
#include "King.h"

class King;

class Rook {
    public:
        Rook();
        void setColor(int color);
        int getColor();
        void setX(char x);
        char getX();
        void setY(int y);
        int getY();
        void setAlive(bool alive);
        bool getAlive();
        std::vector<std::pair<char, int>> getMoves(King ourKing, Rook r1, Rook r2, Rook r3);
        bool checkingKing(King otherKing, King ourKing, Rook r1, Rook r2);
    private:
        int _color; //0 for black, 1 for white
        char _x;
        int _y;
        bool _alive;
};

#endif
