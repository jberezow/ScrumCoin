#ifndef CommandLineUtils_h
#define CommandLineUtils_h

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <functional>
#include <map>

using std::string;
using std::to_string;
using std::vector;
using std::cout;

typedef void(CLI_Manager::*Func)();

class CLI_Manager {
    public:
        struct cli_command {
            string command_name;
            string description;
            public:
                CLI_Manager::Func f;
        };

        vector<cli_command> cli_commands;

        CLI_Manager();

        void help();

        void check_balance();

        void exit_operation();
};

#endif