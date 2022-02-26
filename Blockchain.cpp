#include <Blockchain.h>

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