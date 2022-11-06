#ifndef CommandLineUtils_h
#define CommandLineUtils_h

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <functional>

using std::string;
using std::to_string;
using std::vector;
using std::cout;

vector<command> load_ajimbo_cli_commands();

void help();

void check_balance();

void exit_operation();

struct command {
    string command_name;
    string description;
    std::function<void()> operation;
};

#endif