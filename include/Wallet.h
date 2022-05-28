// Wallet Class: holds blockchain; convenience functions: sum balance, send transaction; 
// main interface with Blockchain
#ifndef Wallet_h
#define Wallet_h

#include <Blockchain.h>
#include <TransactionData.h>

// Wallet Class
class Wallet
{
    private:
        // Wallet Balance
        double balance = 0.0;

        // Private key, only visible to the owner
        string privateKey;

        // Update the Balance
        void update_balance();

        // The blockchain itself
        Blockchain blockchain;

    public:
        // Constructor
        Wallet(Blockchain* chain);

        // The public key that everyone can see
        string publicKey;

        // Calculate and update wallet balance
        double return_balance();

        // Send money, return True if successful
        bool send();
};

#endif