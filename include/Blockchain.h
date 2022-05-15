#ifndef Blockchain_h
#define Blockchain_h

#include <vector>

#include <Block.h>

// Blockchain Class
class Blockchain
{
    private:
        Block create_prime_block();

    public:
        // Public Chain
        std::vector<Block> chain;

        // Constructor
        Blockchain();
    
        // Public Functions
        void add_block(Transaction data);
        bool is_chain_valid();

        // Contrived Example for Testing
        Block *get_latest_block();
};

#endif