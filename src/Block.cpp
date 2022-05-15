#include <Block.h>
#include <TransactionData.h>

using std::string;
using std::to_string;

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