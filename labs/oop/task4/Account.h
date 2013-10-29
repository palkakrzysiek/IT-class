#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
    public:
        Account(float value);
        void credit(float value);
        void debit(float value);
        float getBalance();
    private:
        // float currentSum = 0; -- for safety, but not available till C++11  
        float currentSum;
};


#endif
