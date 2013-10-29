#include "Account.h"

Account::Account(float sum) {
    if (sum < 0){
        std::cerr << "Sum should be positive\n";
        currentSum = 0;
    }
    else
        currentSum = sum;
}
void Account::credit(float value) {
    if (value > 0)
        currentSum += value;
}
void Account::debit(float value) {
    if (currentSum - value < 0) {
        std::cerr << "Debit amount exceeded account balance.\n";
        return;
    }
    if (value > 0)
        currentSum -= value;
}
float Account::getBalance() {
    return currentSum;
}
