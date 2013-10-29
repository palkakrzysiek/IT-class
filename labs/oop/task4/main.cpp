#include <iostream>
#include <cassert>
#include "Database.h"

using namespace std;

bool isEqual(float a, float b) {
    const float err = 1e-3; // should be precise enough as the program in
    // case of account balance cares only about 2 decimal places
    // Because task explicitly asks for using flat type, it would not work for
    // accounts of multimilioners anyway :)  
    return (a - b) * (a - b) <= err * err;
}

int main(int argc, char const* argv[])
{
    Database *accounts = new Database(); // create database without any accounts
    
    cout << "Testing crating account with initialization with negative number..."; 
    // account should be created anyway, but with balance set to 0 
    accounts->addAccount(-2.0); // account with id 0
    assert(isEqual(accounts->getBalance(0), 0));
    cout << " OK.\n";

    cout << "Testing crating account with initialization with positive number..."; 
    accounts->addAccount(30.50); // account with id 1
    assert(isEqual(accounts->getBalance(1), 30.5));
    cout << " OK.\n";

    cout << "Testing increasing account sum..."; 
    accounts->credit(0, 500.33);
    assert(isEqual(accounts->getBalance(0), 500.33));
    cout << " OK.\n";

    cout << "Testing decreasing account sum below the limit..."; 
    accounts->debit(1, 50.00);
    assert(isEqual(accounts->getBalance(1), 30.5));
    cout << " OK.\n";

    cout << "Testing decreasing account sum..."; 
    accounts->debit(1, 20.00);
    assert(isEqual(accounts->getBalance(1), 10.50));
    cout << " OK.\n";
    
    cout << "Done.\n";

    delete accounts;

    return 0;
}
