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

int NullConstructorCheck(Wallet wallet){
    if (wallet.return_balance() == 0.0) {
        return true;
    }
    return false;
};

int ChainyConstructorCheck(Wallet wallet, int expected) {
    if (wallet.return_balance() == expected) {
        return true;
    }
    return false;
}

int BalanceCheck(Wallet wallet, int expected_amount) {
    if (wallet.return_balance() == expected_amount) {
        return true;
    }
    return false;
}

int main() {

    std::cout << "Running Test: Wallet" << std::endl << "\n";

    string userPublicKey = "The Chris";
    // Wallet null constructor check
    cout << "Null Constructor Check... \n";
    Wallet testWallet = Wallet(NULL, userPublicKey);
    if (!NullConstructorCheck(testWallet)) {
        throw std::logic_error("Null Constructor test failed.\n");
    }
    else {
        cout << "Test passed\n";
    }

    // Create starter blockchain for test
    cout << "Chainy Constructor Check... \n";
    double trxnAmount = 100.0;
    Blockchain testChain = Blockchain();
    Transaction trxn;
    time_t trxnTime;
    trxn.amount = trxnAmount;
    trxn.receiverKey = userPublicKey;
    trxn.senderKey = "Mayer Joey";
    trxn.timestamp = time(&trxnTime);
    testChain.add_block(trxn);
    testWallet = Wallet(&testChain, userPublicKey);
    if (!ChainyConstructorCheck(testWallet, trxnAmount)) {
        throw std::logic_error("Non-null constructor test failed.\n");
    }
    else {
        cout << "Test passed\n";
    }

    // Balance check test
    double expectedAmount = trxnAmount;
    cout << "Balance Check... \n";
    if (!BalanceCheck(testWallet, expectedAmount)) {
        throw std::logic_error("Balance check failed.\n");
    }
    else {
        cout << "Test passed\n";
    }

    std::cout << "\n";
    return 0;
}
