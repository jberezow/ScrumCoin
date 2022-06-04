// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include <Blockchain.h>

using std::string;
using std::to_string;

void do_cryptocurrency() {
    std::cout << "Cryptocurrency processing... \n";
};

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

    // Check Balance
    // Check Transaction History
    // Send Transaction

    return 0;
}

