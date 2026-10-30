#ifndef KING_H
#define KING_H

#include "Rook.h"
#include <vector>
#include <utility>

class Rook;


class King {
    public:
        King();
        void setColor(int color);
        int getColor();
        void setX(char x);
        char getX();
        void setY(int y);
        int getY();
        void setCheck(bool check);
        bool getCheck();
        std::vector<std::pair<char, int>> getMoves(King otherKing, Rook ourRook1, Rook ourRook2, Rook otherRook1, Rook otherRook2);

    private:
        int _color; //0 for black, 1 for white
        bool _inCheck;
        char _x;
        int _y;


};

#endif
