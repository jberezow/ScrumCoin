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

// TODO: Load the relevant function into the struct

// Eventually read from textfile
vector<command> load_ajimbo_cli_commands() {
    command exit_command {
        "Exit",
        "Exits the program",
        exit_operation,
    };
    command check_balance_command {
        "Check Balance",
        "Checks current wallet balance",
		check_balance,
    };
	command help_command {
		"Help",
		"Displays command line options",
		help
	};
	vector<command> commands;
    commands.push_back(exit_command);
    commands.push_back(check_balance_command);
	commands.push_back(help_command);
	return commands;
}

void help() {
    cout << "Here are your options:\n";
	vector<command> commands = load_ajimbo_cli_commands();
    for (command cmd: commands) {
        cout << cmd.command_name << ": " << cmd.description << "\n";
    }
    cout << "\n";
}

void check_balance() {
	cout << "NOT YET IMPLEMENTED" << "\n";
}

void exit_operation() {
	cout << "Goodbye!" << "\n";
}

