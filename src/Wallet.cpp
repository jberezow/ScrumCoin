#include <Wallet.h>
#include <Blockchain.h>
#include <stdexcept>
#include <iostream>


// Wallet Constructor
Wallet::Wallet(Blockchain* chain, string userPublicKey)
{
    publicKey = userPublicKey;

    if (chain == NULL) {
        blockchain = Blockchain();
    } else {
        blockchain = *chain;
        summarize_user_transactions();
    };
}

void Wallet::update_balance(double value) {
    balance += value;
}

void Wallet::summarize_user_transactions() {
    if (&blockchain == NULL) {
        throw std::logic_error("Blockchain null.\n");
    };

    //std::cout << blockchain.chain.size() << "\n";

    for (int i = 0; i < blockchain.chain.size(); i++) {
        Transaction trxn = blockchain.chain[i].data;
        //std::cout << trxn.senderKey << "\n";
        if (trxn.receiverKey == publicKey) {
            update_balance(trxn.amount);
            std::cout << "Updated balance, we got paid " << trxn.amount << "\n";
        }
        else if (trxn.senderKey == publicKey) {
            update_balance(-trxn.amount);
            std::cout << "Updated balance, we spent " << trxn.amount << "\n";
        }
    }
}

double Wallet::return_balance()
{
    return balance;
}