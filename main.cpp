// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using std::string;
using std::to_string;

void do_cryptocurrency() {
    std::cout << "Cryptocurrency processing... \n";
};

// Transaction Data
struct Transaction {
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
};

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

// Constructor with Parameters
Block::Block(int idx, Transaction d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generate_hash();
}

// Private Functions
size_t Block::generate_hash()
{
    std::hash<string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalHash;
    string toHash = to_string(data.amount) 
        + data.receiverKey 
        + data.senderKey 
        + to_string(data.timestamp);
    
    return finalHash(hash1(toHash) + hash2(previousHash));
};

// Public Functions
size_t Block::get_hash()
{
    return blockHash;
}

size_t Block::get_previous_hash()
{
    return previousHash;
}

bool Block::is_hash_valid()
{
    return generate_hash() == blockHash;
}

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

// Blockchain Constructor
Blockchain::Blockchain()
{
    Block prime = create_prime_block();
    chain.push_back(prime);
}

Block Blockchain::create_prime_block()
{
    time_t current;
    Transaction d;
    d.amount = 0;
    d.receiverKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);

    std::hash<int> hash1;
    Block prime(0, d, hash1(0));
    return prime;
}

// Only for demonstration
Block *Blockchain::get_latest_block()
{
    return &chain.back();
}

void Blockchain::add_block(Transaction d)
{
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, get_latest_block()->get_hash());
};

bool Blockchain::is_chain_valid()
{
    std::vector<Block>::iterator i;
    int chainLen = (int)chain.size();

    for (i = chain.begin(); i != chain.end(); ++i)
    {
        Block currentBlock = *i;
        if (!currentBlock.is_hash_valid())
        {
            return false;
        }

        if(chainLen > 1)
        {
            Block previousBlock = *(i-1);
            if (currentBlock.get_previous_hash() != previousBlock.get_hash())
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // It Begins
    Blockchain ScrumCoin;

    // Data for Prime Block
    Transaction data1;
    time_t data1Time;
    data1.amount = 1.0;
    data1.receiverKey = "Joey Prime";
    data1.senderKey = "Mayer Joey";
    data1.timestamp = time(&data1Time);

    ScrumCoin.add_block(data1);

    std::cout << "Is chain valid?" << std::endl
        << ScrumCoin.is_chain_valid() << std::endl;

    std::cout << "Cryptocurrency complete.";
    return 0;
}

