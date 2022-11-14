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

void CLI_Manager::initialize() {
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
    CLI_Manager::cli_commands = {
        help_cli_command,
        check_balance_cli_command
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
	cout << "NOT YET IMPLEMENTED" << "\n";
}
