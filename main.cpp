// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <functional>

#include <Blockchain.h>
#include <Wallet.h>
#include <CommandLineUtils.h>

using std::string;
using std::to_string;
using std::vector;
using std::cout;

int main() {
    // It Begins
    string userPublicKey = "Mayer Joey";
    Blockchain ScrumCoin;
    Wallet wallet = Wallet(&ScrumCoin, userPublicKey);
    CLI_Manager::initialize(wallet);

    // Data for Prime Block
    Transaction data1;
    time_t data1Time;
    data1.amount = 100.0;
    data1.receiverKey = "Joey Prime";
    data1.senderKey = userPublicKey;
    data1.timestamp = time(&data1Time);
    ScrumCoin.add_block(data1);
    

    // CLI Loop
    cout << "Welcome to ScrumCoin\n";
    
    while (true) {
        cout << "What would you like to do?\n";
        std::vector<std::string> args;
        std::string s;
        while (std::getline(std::cin, s, '\n')) {
            args.push_back(s);
        }

        std::string selection = args[0];

        if (selection == "exit" || selection == "1") {
            break;
        }

        // TODO: Bring this into CLI manager function & implement command aliases
        for (CLI_Manager::cli_command command : CLI_Manager::cli_commands) {
            if (selection == command.command_name) {
                command.operation();
            }
        }
    }

    return 0;
}

