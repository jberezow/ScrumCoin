// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include <Blockchain.h>

using std::string;
using std::to_string;

int main() {
    // It Begins
    Blockchain ScrumCoin;

    // Data for Prime Block
    Transaction data1;
    time_t data1Time;
    data1.amount = 100.0;
    data1.receiverKey = "Joey Prime";
    data1.senderKey = "Mayer Joey";
    data1.timestamp = time(&data1Time);

    ScrumCoin.add_block(data1);

    std::cout << "Is chain valid?" << std::endl;
    std::cout << ScrumCoin.is_chain_valid() << std::endl;

    std::cout << "Does chain contain several blocks?" << std::endl;
    std::cout << (ScrumCoin.chain.size() >= 2) << std::endl; 

    std::cout << "Cryptocurrency complete. \n";
    return 0;
}
