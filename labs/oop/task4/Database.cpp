#include "Database.h"

Database::Database() {
    std::cout << "Database has been created\n";
}
int Database::addAccount(float initSum) {
    accounts.push_back(Account(initSum));
    return accounts.size() - 1; // return account id
}
void Database::credit(int accountId, float value) {
    accounts[accountId].credit(value);
}

void Database::debit(int accountId, float value) {
    accounts[accountId].debit(value);
}

float Database::getBalance(int accountId) {
    return accounts[accountId].getBalance();
}
