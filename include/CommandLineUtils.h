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

class CLI_Manager {
    static void help();

    static void check_balance();

    public: 
        struct cli_command {
            string command_name;
            string description;
            std::function<void()> operation;
        };

        static void initialize();

        static vector<cli_command> cli_commands;
};

#endif