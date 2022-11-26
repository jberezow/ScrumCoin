#include <Wallet.h>
#include <Blockchain.h>
#include <stdexcept>
#include <iostream>

// Empty constructor
Wallet::Wallet() {};
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
    // TODO: We should be maintaining a state that
    // indicates what the last checked transaction was
    balance = 0;
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

bool Wallet::send(double amount, string recipient) {
    try {
        Transaction trxn;
        time_t trxnTime;
        trxn.amount = amount;
        trxn.receiverKey = recipient;
        trxn.senderKey = publicKey;
        trxn.timestamp = time(&trxnTime);
        
        blockchain.add_block(trxn);
        summarize_user_transactions();
        return true;
    }
    catch (std::exception e) {
        std::cout << "Send failed" << "\n";
        std::cout << e.what() << "\n";
        return false;
    }
}