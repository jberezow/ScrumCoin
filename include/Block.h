#ifndef Block_h
#define Block_h

#include <TransactionData.h>

// Block Class
class Block
{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generate_hash();

    public:
        // Constructor
        Block(int idx, Transaction d, size_t prevHash);

        // Get Original Hash
        size_t get_hash();

        // Get Previous Hash
        size_t get_previous_hash();

        // Transaction Data
        Transaction data;

        // Validate Hash
        bool is_hash_valid();
};

#endif