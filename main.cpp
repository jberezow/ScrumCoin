// ScrumCoin
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include <Blockchain.h>

using std::string;
using std::to_string;
using std::vector;
using std::cout;

// TODO: Load the relevant function into the struct
struct command {
    string command_name;
    string description;
};
vector<command> commands;

// Eventually read from textfile
void load_commands() {
    command exit {
        "Exit",
        "Exits the program"
    };
    command check_balance {
        "Check Balance",
        "Checks current wallet balance"
    };
    commands.push_back(exit);
    commands.push_back(check_balance);
}

void help() {
    cout << "Here are your options:\n";
    for (command cmd: commands) {
        cout << cmd.command_name << ": " << cmd.description << "\n";
    }
    cout << "\n";
}

int main() {
    // It Begins
    Blockchain ScrumCoin;
    load_commands();

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
        if (selection == "help" || selection == "h") {
            help();
        }
        if (selection == "exit" || selection == "1") {
            std::cout << "Goodbye!" << "\n";
            break;
        }
        // commands[selection].operation;
    }

    return 0;
}

