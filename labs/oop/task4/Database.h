#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include "Account.h"

class Database {
    public:
        Database();
        int addAccount(float initSum); // return account id
        void credit(int accountId, float value);
        void debit(int accountId, float value);
        float getBalance(int accountId);
    private:
        std::vector<Account> accounts;
};


#endif
