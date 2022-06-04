#include <Wallet.h>
#include <Blockchain.h>

// Wallet Constructor
Wallet::Wallet(Blockchain* chain)
{
    if (chain == NULL) {
        blockchain = Blockchain();
    } else {
        blockchain = *chain;
    };
}

double Wallet::return_balance()
{
    return balance;
}