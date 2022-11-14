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


CLI_Manager::CLI_Manager() {
    cli_command check_balance_cli_command {
        "Check",
        "Checks current wallet balance",
        CLI_Manager::check_balance
    };
    cli_command help_cli_command {
        "Help",
        "Displays cli_command line options",
        CLI_Manager::help
    };
    cli_commands.push_back(check_balance_cli_command);
    cli_commands.push_back(help_cli_command);
    
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

