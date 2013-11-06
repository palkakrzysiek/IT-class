#include "TicTacToe.h"

#include <ctime>
#include <cstdlib>

TicTacToe::TicTacToe(){
    // The constructor
    // should initialize the empty board to all zeros.
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = None;
        }
    }
}

void TicTacToe::displayBoard(){
    using namespace std;
    cout << endl;
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++) {
            switch (board[i][j]) {
                case Player1:
                    cout << "  o\t";
                    break;
                case Player2:
                    cout << "  x\t";
                    break;
                default:
                    cout << "(" << i << "," << j << ")\t";
                    break;
            }
        }
        cout << endl;
    }
}

bool TicTacToe::set(int x, int y, int p) {
    // Wrong position
    if (!(x >= 0 && y >= 0 && x < boardSize && y < boardSize))
        return false;
    // Wrong player
    if (!(p == None || p == Player1 || p == Player2))
        return false;
    // Field not empty
    if (board[x][y] != 0) {
        return false;
    }
    // Everything OK
    else {
        board[x][y] = p;
        return true;
    }
}

int TicTacToe::getStatus() {

    int emptyFileds = 0;
    for (int k = 0; k < masksCounter; k++) {
        bool p1Won = true;
        bool p2Won = true;
        emptyFileds = boardSize * boardSize;
        for (int i = 0; i < boardSize; i++){
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] != None) {
                    emptyFileds--;
                }
                if (mask[k][i][j] && board[i][j] != Player1) {
                    p1Won = false;
                }
                if (mask[k][i][j] && board[i][j] != Player2) {
                    p2Won = false;
                }
            }
        }
        if (p1Won) {
            return Player1;
        }
        if (p2Won) {
            return Player2;
        }
    }
    if (emptyFileds == 0) {
        return Draw;
    }
    return None;
}

void Player::move(TicTacToe & game) {
    using namespace std;
    if (!artificial) {
        int x = 0, y = 0;
        do {
        cout << "Enter position [row column] to which you want to insert a " <<
          (id == Player1 ? "circle" : "cross" ) << ": ";
            cout << "X coordinate: ";
            while (!(cin >> x)) {
                cout << "Wrong x coordinate, try again: ";
                cin.clear();
                while (cin.get() != '\n') {continue;}
            }
            cout << "Y coordinate: ";
            while (!(cin >> y)) {
                cout << "Wrong y coordinate, try again: ";
                cin.clear();
                while (cin.get() != '\n') {continue;}
            }
#ifndef _NDEBUG
std::cout << "\nx = " << x << " y = " << y << std::endl;
#endif
        } while (!game.set(x, y, id) && (std::cout << "Wrong coordinates\n"));
    }
    else {

        // Computer as second player 
        int opponentsId = (id == Player1 ? Player2 : Player1);

        for (int k = 0; k < masksCounter; k++) {

            // first, search for field in which if player make mark, he'll win

            int matchingFields = 0;
            for (int i = 0; i < boardSize; i++){
                for (int j = 0; j < boardSize; j++) {
                    if (mask[k][i][j] && game.board[i][j] == opponentsId) {
                        matchingFields--;
                    }
                    if (mask[k][i][j] && game.board[i][j] == id) {
                        matchingFields++;
                    }
                }
            }

            if (matchingFields == 2) { 
#ifndef _NDEBUG
std::cout << "player " << id << ": it's possible to win, mask " << k <<
    ", insert into:";
#endif
                for (int i = 0; i < boardSize; i++){
                    for (int j = 0; j < boardSize; j++) {
                        if (mask[k][i][j] && game.board[i][j] == None) {
                            game.set(i, j, id);
#ifndef _NDEBUG
std::cout << "x = " << i << " y = " << j << std::endl;
#endif
                            return;
                        }
                    }
                }

            }
        }
        for (int k = 0; k < masksCounter; k++) {

            // next, search for field in which if opponent make mark, then
            // player loose


            int matchingFields = 0;
            for (int i = 0; i < boardSize; i++){
                for (int j = 0; j < boardSize; j++) {
                    if (mask[k][i][j] && game.board[i][j] == opponentsId) {
                        matchingFields++;
                    }
                    if (mask[k][i][j] && game.board[i][j] == id) {
                        matchingFields--;
                    }
                }
            }

            if (matchingFields == 2) { // that means if in one line there 
               // are 2 opponent's fields and one empty field
#ifndef _NDEBUG
std::cout << "player " << id << ": opponent can win if player will not block his field, mask " << k <<
    ", insert into:";
#endif
                for (int i = 0; i < boardSize; i++){
                    for (int j = 0; j < boardSize; j++) {
                        if (mask[k][i][j] && game.board[i][j] == None) {
                            game.set(i, j, id);
#ifndef _NDEBUG
std::cout << "x = " << i << " y = " << j << std::endl;
#endif
                            return;
                        }
                    }
                }

            }
        }
        for (int k = 0; k < masksCounter; k++) {

            // next, try to mark field in which at least 1 player's mark already exist

            int matchingFields = 0;
            for (int i = 0; i < boardSize; i++){
                for (int j = 0; j < boardSize; j++) {
                    if (mask[k][i][j] && game.board[i][j] == opponentsId) {
                        matchingFields -= 2; // if opponent marked field in line
                        // don't try to put any field there 
                    }
                    if (mask[k][i][j] && game.board[i][j] == id) {
                        matchingFields++;
                    }
                }
            }

            if (matchingFields == 1) { 
#ifndef _NDEBUG
std::cout << "player " << id << ": in current line exist one player's field, mask " << k <<
    ", insert into:";
#endif
                for (int i = 0; i < boardSize; i++){
                    for (int j = 0; j < boardSize; j++) {
                        if (mask[k][i][j] && game.board[i][j] == None) {
                            game.set(i, j, id);
#ifndef _NDEBUG
std::cout << "x = " << i << " y = " << j << std::endl;
#endif
                            return;
                        }
                    }
                }
            }
        }
        // finally try to mark any field
#ifndef _NDEBUG
std::cout << "player " << id << ": mark random field, insert into:";
#endif
        srandom(time(0));
        int x = 0, y = 0;
        x = random() % boardSize;
        y = random() % boardSize;
#ifndef _NDEBUG
std::cout << "\nx = " << x << " y = " << y << std::endl;
#endif
        while (!game.set(x, y, id)){
            x = random() % boardSize;
            y = random() % boardSize;
#ifndef _NDEBUG
std::cout << "\nx = " << x << " y = " << y << std::endl;
#endif
        }
    }
    
}
