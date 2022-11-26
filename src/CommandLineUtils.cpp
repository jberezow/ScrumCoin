#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <functional>

#include <Blockchain.h>
#include <CommandLineUtils.h>

using std::string;
using std::to_string;
using std::vector;
using std::cout;


vector<CLI_Manager::cli_command> CLI_Manager::cli_commands = {};
Wallet CLI_Manager::activeWallet = Wallet();

void CLI_Manager::initialize(Wallet wallet) {
    // Initialize wallet
    activeWallet = wallet;

    // Initialize commands
    CLI_Manager::cli_command check_balance_cli_command {
        "Check",
        "Checks current wallet balance",
        check_balance
    };
    cli_command help_cli_command {
        "Help",
        "Displays cli_command line options",
        help
    };
    cli_command send_cli_command {
        "Send",
        "Send money to Joey",
        send
    };
    CLI_Manager::cli_commands = {
        help_cli_command,
        check_balance_cli_command,
        send_cli_command
    };
    std::cout << "Initialized command list with " << cli_commands.size() << " entries \n";
};
// Eventually read from textfile

void CLI_Manager::help() {
    cout << "Here are your options:\n";
    for (cli_command cmd: cli_commands) {
        cout << cmd.command_name << ": " << cmd.description << "\n";
    }
    cout << "\n";
}
void CLI_Manager::check_balance() {
	cout << "Your balance: " << activeWallet.return_balance() << "\n";
}

void CLI_Manager::send() {
	cout << "IMPLEMENT NEXT" << "\n";
}