#include "TicTacToe.h"
#include <iostream>

int main(int argc, char const* argv[])
{
    using namespace std;
    char answer;
    cout << "Player 1 [circle] begins, should it be human (enter h) or computer (enter c): ";
    cin >> answer;
    while (!(answer == 'h' || answer == 'c')){
        cout << "Wrong answer, try again: ";
        cin >> answer;
    }
    Player p1(Player1, (answer == 'c' ? true : false));
    cout << "Player 2 [cross], should it be human (enter h) or computer (enter c): ";
    cin >> answer;
    while (!(answer == 'h' || answer == 'c')){
        cout << "Wrong answer, try again: ";
        cin >> answer;
    }
    Player p2(Player2, (answer == 'c' ? true : false));

    TicTacToe game;
    while (!game.getStatus()){ // until nobody won and there are still empty fields 
        game.displayBoard();
        p1.move(game);
        if (game.getStatus() != None) // if sb. won or there is a draw
            break;
        game.displayBoard();
        p2.move(game);
        if (game.getStatus() != None) // if sb. won or there is a draw
            break;
    }
    game.displayBoard();
    switch (game.getStatus()) {
        case Player1:
            cout << "Player 1 won!\n";
            break;
        case Player2:
            cout << "Player 2 won!\n";
            break;
        default:
            cout << "Draw!\n";
            break;

    }
    return 0;
}
