// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include <Blockchain.h>
#include <CommandLineUtils.h>

using std::string;
using std::to_string;
using std::vector;
using std::cout;

int main() {
    // It Begins
    Blockchain ScrumCoin;
    vector<command> commands = load_ajimbo_cli_commands();

    // Data for Prime Block
    Transaction data1;
    time_t data1Time;
    data1.amount = 100.0;
    data1.receiverKey = "Joey Prime";
    data1.senderKey = "Mayer Joey";
    data1.timestamp = time(&data1Time);
    ScrumCoin.add_block(data1);

    // CLI Loop
    cout << "Welcome to ScrumCoin\n";
    while (true) {
        cout << "What would you like to do?\n";
        string selection;
        std::cin >> selection;

        commands[std::stoi(selection)].operation();

        if (selection == "exit" || selection == "1") {
            break;
        }
    }

    return 0;
}

