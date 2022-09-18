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

int ChainyConstructorCheck(Wallet wallet, int expected_amount) {
    if (wallet.return_balance() == expected_amount) {
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

int SendCheck(Wallet wallet, int expected_amount) {
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
    double startAmount = 100.0;
    Blockchain testChain = Blockchain();
    Transaction trxn;
    time_t trxnTime;
    trxn.amount = startAmount;
    trxn.receiverKey = userPublicKey;
    trxn.senderKey = "Mayer Joey";
    trxn.timestamp = time(&trxnTime);
    testChain.add_block(trxn);
    testWallet = Wallet(&testChain, userPublicKey);
    if (!ChainyConstructorCheck(testWallet, startAmount)) {
        throw std::logic_error("Non-null constructor test failed.\n");
    }
    else {
        cout << "Test passed\n";
    }

    // Balance check test
    double expectedAmount = startAmount;
    cout << "Balance Check... \n";
    if (!BalanceCheck(testWallet, expectedAmount)) {
        throw std::logic_error("Balance check failed.\n");
    }
    else {
        cout << "Test passed\n";
    }

    // Send test
    double sendAmount = 51;
    cout << "Send Check... \n";
    if (testWallet.send(sendAmount, "Mayer Joey")) {
        cout << "Successfully sent money" << "\n";
    }
    else {
        throw std::logic_error("Send failed.\n");
    }
    cout << testWallet.return_balance() << "\n";
    expectedAmount = startAmount - sendAmount;
    if (!SendCheck(testWallet, expectedAmount)) {
        throw std::logic_error("Send check failed.\n");
    }
    else {
        cout << "Test passed\n";
    }
    
    std::cout << "\n";
    return 0;
}
