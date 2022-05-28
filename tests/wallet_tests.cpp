// Test Wallet functionality
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <typeinfo>

#include <Blockchain.h>
#include <Wallet.h>

using std::string;
using std::to_string;
using std::cout;

int testBalanceCheck(Wallet wallet){
    if (wallet.return_balance() == 0.0) {
        return true;
    }
    return false;
};

int main() {
    // Wallet balance check
    cout << "Testing Balance Check... \n";
    Wallet testWallet = Wallet(NULL);
    if (!testBalanceCheck(testWallet)) {
        throw std::logic_error("Balance check failed.\n");
    };

    cout << "All tests passed successfully\n";
    return 0;
}