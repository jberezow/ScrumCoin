// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include <Blockchain.h>

using std::string;
using std::to_string;
using std::cout;

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

    // Test Output

    std::cout << "Running Test: Blockchain" << std::endl << "\n";
    std::cout << "Chain Validity Check..." << std::endl;
    if (!ScrumCoin.is_chain_valid()) {
        throw std::logic_error("Null Constructor test failed.\n");
    }
    else {
        std::cout << "Test passed\n";
    }
    
    std::cout << "Multiple Blocks Check..." << std::endl;
    if (ScrumCoin.chain.size() < 2) {
        throw std::logic_error("Null Constructor test failed.\n");
    }
    else {
        std::cout << "Test passed\n";
    }

    std::cout << "\n";
    return 0;
}

