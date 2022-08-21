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

        // User private key, only visible to the owner
        string privateKey;

        // Update the Balance
        void update_balance(double value);

        // The blockchain itself
        Blockchain blockchain;

        // Walk through the history of the blockchain to 
        // summarize user transactions
        void summarize_user_transactions();

    public:
        // Constructor
        Wallet(Blockchain* chain, string userPublicKey);

        // The public key that everyone can see
        string publicKey;

        // Calculate and update wallet balance
        double return_balance();

        // Send money, return True if successful
        bool send(double amount, string recipient);
    
};

#endif