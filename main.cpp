/* CSCI 200: Final Project: Chess Endgame Simulator
 * 
 * This program is a simulator of a common chess endgame: Kings and rooks. Each side gets two rooks and their king at places
 * of their choosing. The two sides play back and for until a draw or a checkmate is achieved.
 * 
 * 
 * Author: Elyse Wright
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): 
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 * 
 */


#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "King.h"
#include "Rook.h"

int main() {
    std::ofstream fout;
    fout.open("file.out");
    std::cout << "Welcome to the chess endgame simulator! Both sides start with two rooks and a king at places of your choosing." << std::endl;

    //white king
    fout << "White peices:" << std::endl;
    std::cout << "Creating the white king" << std::endl;
    King whiteKing;
    whiteKing.setColor(1);
    char wkx;
    int wky;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> wkx;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> wky;
    whiteKing.setX(wkx);
    whiteKing.setY(wky);
    fout << "K" << wkx << wky << std::endl;

    //white rooks
    std::cout << "Creating the white rook one" << std::endl;
    Rook whiteRookOne;
    whiteRookOne.setColor(1);
    char wr1x;
    int wr1y;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> wr1x;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> wr1y;   
    whiteRookOne.setX(wr1x);
    whiteRookOne.setY(wr1y); 
    fout << "R" << wr1x << wr1y << std::endl;  

    std::cout << "Creating the white rook two" << std::endl;
    Rook whiteRookTwo;
    whiteRookTwo.setColor(1);
    char wr2x;
    int wr2y;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> wr2x;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> wr2y;   
    whiteRookTwo.setX(wr2x);
    whiteRookTwo.setY(wr2y);
    fout << "R" << wr2x << wr2y << std::endl;     

    //black king
    fout << "Black peices:" << std::endl;
    std::cout << "Creating the black king" << std::endl;
    King blackKing;
    blackKing.setColor(0);
    char bkx;
    int bky;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> bkx;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> bky; 
    blackKing.setX(bkx);
    blackKing.setY(bky);
    fout << "K" << bkx << bky << std::endl;  

    //black rooks
    std::cout << "Creating the black rook one" << std::endl;
    Rook blackRookOne;
    blackRookOne.setColor(0);
    char br1x;
    int br1y;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> br1x;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> br1y;  
    blackRookOne.setX(br1x);
    blackRookOne.setY(br1y); 
    fout << "R" << br1x << br1y << std::endl;  

    std::cout << "Creating the black rook two" << std::endl;
    Rook blackRookTwo;
    blackRookTwo.setColor(0);
    char br2x;
    int br2y;
    std::cout << "Enter your file as a char:" << std::endl;
    std::cin >> br2x;
    std::cout << "Enter your rank as an int:" << std::endl;
    std::cin >> br2y;    
    blackRookTwo.setX(br2x);
    blackRookTwo.setY(br2y);   
    fout << "R" << br2x << br2y << std::endl;  

    //play!  
    bool whiteTurn;
    std::cout << "Which side will start? Enter 1 for white and 0 for black"  << std::endl;
    std::cin >> whiteTurn;
    if (whiteTurn) {
        fout << "White to start" << std::endl;
    }
    else {
        fout << "Black to start" << std::endl;
    }

    //game loop
    bool whiteWin = false;
    bool blackWin = false;
    bool draw = false;
    while (true) {
        if (whiteTurn) {
            //get peice to move
            std::string peiceToMove;
            std::cout << "White to move" << std::endl;
            if (whiteKing.getCheck()) {
                std::cout << "You are in check. Enter K to move your king or D to offer a draw" << std::endl;
                std::cin >> peiceToMove;
            }
            if (whiteRookOne.getAlive() && whiteRookTwo.getAlive()) {
                std::cout << "Enter your peice to move: K, R1, R2, or D to offer a draw"  << std::endl;
                std::cin >> peiceToMove;
            }
            else if (whiteRookOne.getAlive() || whiteRookTwo.getAlive()) {
                if (whiteRookOne.getAlive()) {
                std::cout << "Enter your peice to move: K, R1, or D to offer a draw"  << std::endl;
                std::cin >> peiceToMove;                    
                }
                else {
                std::cout << "Enter your peice to move: K, R2, or D to offer a draw"  << std::endl;
                std::cin >> peiceToMove;                    
                }
            }
            else if (!whiteRookOne.getAlive() && !whiteRookTwo.getAlive()) {
                std::cout << "You may move your W king. Enter K to move your king or enter D to offer a draw"  << std::endl;
                std::cin >> peiceToMove;
            }
            if (peiceToMove == "D" || peiceToMove == "d") {
                std::cout << "A draw has been offered. Enter y to accept or n to keep playing" << std::endl;
                char acceptDraw;
                std::cin >> acceptDraw;
                if (acceptDraw == 'y' || acceptDraw == 'Y') {
                    std::cout << "Draw accepted" << std::endl;
                    draw = true;
                    break;
                }
            }

            //move peices
            std::string moveString;
            if (peiceToMove == "K" || peiceToMove == "k") {
                std::vector<std::pair<char, int>> validMoves = whiteKing.getMoves(blackKing, whiteRookOne, whiteRookTwo, blackRookOne, blackRookTwo);
                std::cout << "You may move your king to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                whiteKing.setX(move.first);
                whiteKing.setY(move.second);
                std::cout << "White king moved to " << whiteKing.getX() << whiteKing.getY() << std::endl;
                //if the king takes a peice
                if (whiteKing.getX() == blackRookOne.getX() && whiteKing.getY() == blackRookOne.getY()) {
                    std::cout << "White king takes black rook one" << std::endl;
                    blackRookOne.setAlive(false);
                    moveString = "\nKx" + std::to_string(blackRookOne.getX()) + std::to_string(blackRookOne.getY());
                }
                else if (whiteKing.getX() == blackRookTwo.getX() && whiteKing.getY() == blackRookTwo.getY()) {
                    std::cout << "White king takes black rook one" << std::endl;
                    blackRookTwo.setAlive(false);
                    moveString = "\nKx" + std::to_string(blackRookTwo.getX()) + std::to_string(blackRookTwo.getY());
                }
                else {
                    moveString = "\nK" + std::to_string(whiteKing.getX()) + std::to_string(whiteKing.getY());
                }
                fout << moveString;
                whiteTurn = false;
            }
            if (peiceToMove == "R1" || peiceToMove == "r1") {
                std::vector<std::pair<char, int>> validMoves = whiteRookOne.getMoves(whiteKing, whiteRookTwo, blackRookOne, blackRookTwo);
                std::cout << "You may move your rook to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                whiteRookOne.setX(move.first);
                whiteRookOne.setY(move.second);
                std::cout << "White rook one moved to " << whiteRookOne.getX() << whiteRookOne.getY() << std::endl;
                //check if black king now in check
                if (whiteRookOne.checkingKing(blackKing, whiteKing, blackRookOne, blackRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    blackKing.setCheck(true);
                }
                else if (whiteRookTwo.checkingKing(blackKing, whiteKing, blackRookOne, blackRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    blackKing.setCheck(true);                    
                }
                //if the rook takes a peice
                if (whiteRookOne.getX() == blackRookOne.getX() && whiteRookOne.getY() == blackRookOne.getY()) {
                    std::cout << "White rook one takes black rook one" << std::endl;
                    blackRookOne.setAlive(false);
                    moveString = "\nRx" + std::to_string(blackRookOne.getX()) + std::to_string(blackRookOne.getY());
                }
                else if (whiteRookOne.getX() == blackRookTwo.getX() && whiteRookOne.getY() == blackRookTwo.getY()) {
                    std::cout << "White rook one takes black rook one" << std::endl;
                    blackRookTwo.setAlive(false);
                    moveString = "\nRx" + std::to_string(blackRookTwo.getX()) + std::to_string(blackRookTwo.getY());
                }
                else {
                    moveString = "\nR" + std::to_string(whiteRookOne.getX()) + std::to_string(whiteRookOne.getY());
                }
                fout << moveString;
                whiteTurn = false;
            }
            if (peiceToMove == "R2" || peiceToMove == "r2") {
                std::vector<std::pair<char, int>> validMoves = whiteRookTwo.getMoves(whiteKing, whiteRookOne, blackRookOne, blackRookTwo);
                std::cout << "You may move your rook to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                whiteRookTwo.setX(move.first);
                whiteRookTwo.setY(move.second);
                std::cout << "White rook two moved to " << whiteRookTwo.getX() << whiteRookTwo.getY() << std::endl;
                if (whiteRookTwo.checkingKing(blackKing, whiteKing, blackRookOne, blackRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    blackKing.setCheck(true);
                }
                else if (whiteRookOne.checkingKing(blackKing, whiteKing, blackRookOne, blackRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    blackKing.setCheck(true);                    
                }
                //if the rook takes a peice
                if (whiteRookTwo.getX() == blackRookOne.getX() && whiteRookTwo.getY() == blackRookOne.getY()) {
                    std::cout << "White rook two takes black rook one" << std::endl;
                    blackRookOne.setAlive(false);
                    moveString = "\nRx" + std::to_string(blackRookOne.getX()) + std::to_string(blackRookOne.getY());
                }
                else if (whiteRookTwo.getX() == blackRookTwo.getX() && whiteRookTwo.getY() == blackRookTwo.getY()) {
                    std::cout << "White rook two takes black rook one" << std::endl;
                    blackRookTwo.setAlive(false);
                    moveString = "\nRx" + std::to_string(blackRookTwo.getX()) + std::to_string(blackRookTwo.getY());
                }
                else {
                    moveString = "\nR" + std::to_string(whiteRookTwo.getX()) + std::to_string(whiteRookTwo.getY());
                }
                fout << moveString;
                whiteTurn = false;
            }
            //check if black now in checkmate
            std::vector<std::pair<char, int>> blackKingvalidMoves = blackKing.getMoves(whiteKing, blackRookOne, blackRookTwo, whiteRookOne, whiteRookTwo);
            if (blackKingvalidMoves.empty()) {
                std::cout << "Checkmate!" << std::endl;
                whiteWin = true;
                fout << "#";
                break;
            }
        }
        if (!whiteTurn) {
            //get peice to move
            std::string peiceToMove;
            std::cout << "black to move" << std::endl;
            if (blackKing.getCheck()) {
                std::cout << "You are in check. Enter K to move your king or D to offer a draw" << std::endl;
                std::cin >> peiceToMove;
            }
            if (blackRookOne.getAlive() && blackRookTwo.getAlive()) {
                std::cout << "Enter your peice to move: K, R1, R2, or D to offer a draw";
                std::cin >> peiceToMove;
            }
            else if (blackRookOne.getAlive() || blackRookTwo.getAlive()) {
                if (blackRookOne.getAlive()) {
                std::cout << "Enter your peice to move: K, R1, or D to offer a draw";
                std::cin >> peiceToMove;                    
                }
                else {
                std::cout << "Enter your peice to move: K, R2, or D to offer a draw";
                std::cin >> peiceToMove;                    
                }
            }
            else if (!blackRookOne.getAlive() && !blackRookTwo.getAlive()) {
                std::cout << "You may move your B king. Enter K to move your king or enter D to offer a draw" << std::endl;
                std::cin >> peiceToMove;
            }
            if (peiceToMove == "D" || peiceToMove == "d") {
                std::cout << "A draw has been offered. Enter y to accept or n to keep playing" << std::endl;
                char acceptDraw;
                std::cin >> acceptDraw;
                if (acceptDraw == 'y' || acceptDraw == 'Y') {
                    std::cout << "Draw accepted" << std::endl;
                    draw = true;
                    break;
                }
            }
            //move peices
            std::string moveString;
            if (peiceToMove == "K" || peiceToMove == "k") {
                std::vector<std::pair<char, int>> validMoves = blackKing.getMoves(whiteKing, blackRookOne, blackRookTwo, whiteRookOne, whiteRookTwo);
                std::cout << "You may move your king to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                blackKing.setX(move.first);
                blackKing.setY(move.second);
                std::cout << "black king moved to " << blackKing.getX() << blackKing.getY() << std::endl;
                //if the king takes a peice
                if (blackKing.getX() == whiteRookOne.getX() && blackKing.getY() == whiteRookOne.getY()) {
                    std::cout << "black king takes white rook one" << std::endl;
                    whiteRookOne.setAlive(false);
                    moveString = "\nKx" + std::to_string(whiteRookOne.getX()) + std::to_string(whiteRookOne.getY());
                }
                else if (blackKing.getX() == whiteRookTwo.getX() && blackKing.getY() == whiteRookTwo.getY()) {
                    std::cout << "black king takes white rook one" << std::endl;
                    whiteRookTwo.setAlive(false);
                    moveString = "\nKx" + std::to_string(whiteRookTwo.getX()) + std::to_string(whiteRookTwo.getY());
                }
                else {
                    moveString = "\nK" + std::to_string(blackKing.getX()) + std::to_string(blackKing.getY());
                }
                fout << moveString;
                whiteTurn = true;
            }
            if (peiceToMove == "R1" || peiceToMove == "r1") {
                std::vector<std::pair<char, int>> validMoves = blackRookOne.getMoves(blackKing, blackRookTwo, whiteRookOne, whiteRookTwo);
                std::cout << "You may move your rook to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                blackRookOne.setX(move.first);
                blackRookOne.setY(move.second);
                std::cout << "black rook one moved to " << blackRookOne.getX() << blackRookOne.getY() << std::endl;
                //check if white king now in check
                if (blackRookOne.checkingKing(whiteKing, blackKing, whiteRookOne, whiteRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    whiteKing.setCheck(true);
                }
                else if (blackRookTwo.checkingKing(whiteKing, blackKing, whiteRookOne, whiteRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    whiteKing.setCheck(true);                    
                }
                //if the rook takes a peice
                if (blackRookOne.getX() == whiteRookOne.getX() && blackRookOne.getY() == whiteRookOne.getY()) {
                    std::cout << "black rook one takes white rook one" << std::endl;
                    whiteRookOne.setAlive(false);
                    moveString = "\nRx" + std::to_string(whiteRookOne.getX()) + std::to_string(whiteRookOne.getY());
                }
                else if (blackRookOne.getX() == whiteRookTwo.getX() && blackRookOne.getY() == whiteRookTwo.getY()) {
                    std::cout << "black rook one takes white rook one" << std::endl;
                    whiteRookTwo.setAlive(false);
                    moveString = "\nRx" + std::to_string(whiteRookTwo.getX()) + std::to_string(whiteRookTwo.getY());
                }
                else {
                    moveString = "\nR" + std::to_string(blackRookOne.getX()) + std::to_string(blackRookOne.getY());
                }
                fout << moveString;
                whiteTurn = true;
            }
            if (peiceToMove == "R2" || peiceToMove == "r2") {
                std::vector<std::pair<char, int>> validMoves = blackRookTwo.getMoves(blackKing, blackRookOne, whiteRookOne, whiteRookTwo);
                std::cout << "You may move your rook to: ";
                int choice;
                for (size_t i = 0; i < validMoves.size(); i++) {
                    std::cout << (i + 1) << ") " << validMoves.at(i).first << validMoves.at(i).second << " ";
                }
                std::cout << std::endl;
                std::cout << "Enter your choice as an integer:" << std::endl;
                std::cin >> choice;
                std::pair<char, int> move = validMoves.at(choice - 1);
                blackRookTwo.setX(move.first);
                blackRookTwo.setY(move.second);
                std::cout << "black rook two moved to " << blackRookTwo.getX() << blackRookTwo.getY() << std::endl;
                if (blackRookTwo.checkingKing(whiteKing, blackKing, whiteRookOne, whiteRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    whiteKing.setCheck(true);
                }
                else if (blackRookOne.checkingKing(whiteKing, blackKing, whiteRookOne, whiteRookTwo)) {
                    std::cout << "Check!" << std::endl;
                    whiteKing.setCheck(true);                    
                }
                //if the rook takes a peice
                if (blackRookTwo.getX() == whiteRookOne.getX() && blackRookTwo.getY() == whiteRookOne.getY()) {
                    std::cout << "black rook two takes white rook one" << std::endl;
                    whiteRookOne.setAlive(false);
                    moveString = "\nRx" + std::to_string(whiteRookOne.getX()) + std::to_string(whiteRookOne.getY());
                }
                else if (blackRookTwo.getX() == whiteRookTwo.getX() && blackRookTwo.getY() == whiteRookTwo.getY()) {
                    std::cout << "black rook two takes white rook one" << std::endl;
                    whiteRookTwo.setAlive(false);
                    moveString = "\nRx" + std::to_string(whiteRookTwo.getX()) + std::to_string(whiteRookTwo.getY());
                }
                else {
                    moveString = "\nR" + std::to_string(blackRookTwo.getX()) + std::to_string(blackRookTwo.getY());
                }
                fout << moveString;
                whiteTurn = true;
            }
            //check if white now in checkmate
            std::vector<std::pair<char, int>> whiteKingvalidMoves = whiteKing.getMoves(blackKing, whiteRookOne, whiteRookTwo, blackRookOne, blackRookTwo);
            if (whiteKingvalidMoves.empty()) {
                std::cout << "Checkmate!" << std::endl;
                blackWin = true;
                fout << "#";
                break;
            }
        }
    }
    if (draw) {
        std::cout << "Game over via draw";
        fout << "Game over via draw";
    }
    if (whiteWin) {
        std::cout << "White is the champion!";
    }
    if (blackWin) {
        std::cout << "Black is the champion";
    }




    return 0;
}