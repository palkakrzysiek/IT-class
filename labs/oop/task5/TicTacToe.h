//  Create a class TicTacToe that will enable you to write a complete program
//  to play the game  of tic-tac-toe.

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

const int boardSize = 3;
const int masksCounter = 8;
const bool mask[masksCounter][boardSize][boardSize] = {
    {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}
    },
    {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    },
    {
        {0, 0, 0},
        {0, 0, 0},
        {1, 1, 1}
    },
    {
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    },
    {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    },
    {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    }
};

enum {
    None = 0,
    Player1 = 1,
    Player2 = 2,
    Draw = 3
};

class TicTacToe {
    public:
        friend class Player; // Make Player class able to search in board field
        TicTacToe();
        bool set(int x, int y, int p);
        int getStatus();
        void displayBoard();
    private:
        // The class contains as private data a 3-by-3 two-dimensional array
        // of integers.
        int board[boardSize][boardSize];
};

class Player {
    public:
        Player(int i, bool a = false) : id(i), artificial(a) {}
        void move(TicTacToe & game);
    private:
        int id;
        bool artificial;
};

#endif
