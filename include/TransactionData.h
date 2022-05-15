#ifndef TransactionData_h
#define TransactionData_h

#include <ctime>
#include <string>

using std::string;

// Transaction Data
struct Transaction {
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
};

#endif