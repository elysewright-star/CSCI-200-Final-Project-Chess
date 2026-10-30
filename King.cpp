#include "King.h"
#include <iostream>

King::King() {
}
void King::setColor(int color) {
    _color = color;
}
int King::getColor() {
    return _color;
}
void King::setX(char x) { 
    _x = x;
}
char King::getX() {
    return _x;
}
void King::setY(int y) {
    _y = y;
}
int King::getY() {
    return _y;
}
void King::setCheck(bool check) {
    _inCheck = check;
}
bool King::getCheck() {
    return _inCheck;
}
std::vector<std::pair<char, int>> King::getMoves(King otherKing, Rook ourRook1, Rook ourRook2, Rook otherRook1, Rook otherRook2) {
    std::vector<std::pair<int, int>> changes = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    std::vector<std::pair<char, int>> validMoves;
    for (auto change : changes) {
        if (_x + change.first == ('a'-1) || _x + change.first == ('h'+1)) {
            continue;
        }
        if (_y + change.second == 0 || _y + change.second == 9) {
            continue;
        }
        if (ourRook1.getAlive() && _x + change.first == ourRook1.getX() && _y + change.second == ourRook1.getY()) {
            continue;
        }
        if (ourRook2.getAlive() && _x + change.first == ourRook2.getX() && _y + change.second == ourRook2.getY()) {
            continue;
        }        
        if (otherRook1.getAlive() && _x + change.first == otherRook1.getX() && _y + change.second == otherRook1.getY()) {
            validMoves.push_back(std::make_pair(_x + change.first, _y + change.second));
        }
        if (otherRook2.getAlive() && _x + change.first == otherRook2.getX() && _y + change.second == otherRook2.getY()) {
            validMoves.push_back(std::make_pair(_x + change.first, _y + change.second));
        }
        // should check if our rooks are in the way
        if (otherRook1.getAlive() && (_x + change.first == otherRook1.getX() || _y + change.second == otherRook1.getY())) {
            continue;
        }
        if (otherRook2.getAlive() && (_x + change.first == otherRook2.getX() || _y + change.second == otherRook2.getY())) {
            continue;
        }
        if (otherKing.getX() == _x + change.first) {
            if (otherKing.getY() == _y + change.second) {
                continue;
            }
        }
        if (otherKing.getY() == _y + change.second) {
            if (otherKing.getX() == _y + change.first) {
                continue;
            }
        }        
        validMoves.push_back(std::make_pair(_x + change.first, _y + change.second));
    }
    return validMoves;
}
