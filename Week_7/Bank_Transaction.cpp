#include <bits/stdc++.h>
using namespace std;

class Time {
private:
    int seconds;

public:
    Time(string time) {
        int h, m, s;
        sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
        seconds = s + 60 * m + 3600 * h;
    }

    int getTime() {
        return seconds;
    }
};

class Transaction {
private:
    string from_account;
    string to_account;
    int money;
    Time time_point;
    string atm;

public:
    Transaction(const string& from_account, const string& to_account, const int& money, const Time& time_point, const string& atm) :
        from_account(from_account), to_account(to_account), money(money), time_point(time_point), atm(atm) {}

    string get_from_account() const {
        return from_account;
    }

    string get_to_account() const {
        return to_account;
    }

    int get_money() const {
        return money;
    }

    Time get_time_point() const {
        return time_point;
    }

    string get_atm() const {
        return atm;
    }
};

class Bank {
private:
    vector<Transaction> transactions;
    int totalTransactions;
    int totalMoneyTransactions;
    set<string> accounts;
    unordered_map<string, int> transactionFromAccount;

public:
    Bank() : totalMoneyTransactions(0), totalTransactions(0) {}

    void add_Transaction(const Transaction& transaction) {
        totalTransactions++;
        int amount = transaction.get_money();
        totalMoneyTransactions += amount;

        string accountSendId = transaction.get_from_account();
        string accountGetId = transaction.get_to_account();
        accounts.insert(accountGetId);
        accounts.insert(accountSendId);

        transactionFromAccount[accountSendId] += amount;

        transactions.push_back(transaction);
    }

    int get_number_transactions() const {
        return totalTransactions;
    }

    int get_total_money_transaction() const {
        return totalMoneyTransactions;
    }

    set<string> get_list_sorted_accounts() {
        return accounts;
    }

    int get_total_money_transaction_from(string account) {
        return transactionFromAccount[account];
    }

    int get_inspect_cycle(const string& startAccount, int k) {
        unordered_map<string, int> visitedAccount;
        visitedAccount[startAccount]++;
        return has_cycle(visitedAccount, startAccount, startAccount, k) ? 1 : 0;
    }

private:
    bool has_cycle(unordered_map<string, int>& visitedAccount, const string& startAccount, const string& currentAccount, int k) {
        if (k == 0 && currentAccount == startAccount && visitedAccount[currentAccount] == 2) {
            return true;
        }

        if (k < 0) {
            return false;
        }

        if(currentAccount != startAccount && visitedAccount[currentAccount] >= 1) {
            return false;
        }

        visitedAccount[currentAccount]++;

        for (const auto& transaction : transactions) {
            if (transaction.get_from_account() == currentAccount && transaction.get_to_account() != currentAccount) {
                if (has_cycle(visitedAccount, startAccount, transaction.get_to_account(), k - 1)) {
                    return true;
                }
            }
        }

        visitedAccount[currentAccount]--;

        return false;
    }
};

int main() {
    string line;
    Bank bank;
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string from_account, to_account, time_point, atm;
        int money;

        iss >> from_account >> to_account >> money >> time_point >> atm;
        Time timeObj(time_point);
        Transaction newTrans(from_account, to_account, money, timeObj, atm);
        bank.add_Transaction(newTrans);
    }

    vector<string> res;

    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string queryType;

        iss >> queryType;

        if (queryType == "?number_transactions") {
            res.push_back(to_string(bank.get_number_transactions()));
        } else if (queryType == "?total_money_transaction") {
            res.push_back(to_string(bank.get_total_money_transaction()));
        } else if (queryType == "?list_sorted_accounts") {
            set<string> sortedAccounts = bank.get_list_sorted_accounts();
            for (const auto& account : sortedAccounts) {
                res.push_back(account);
            }
        } else if (queryType == "?total_money_transaction_from") {
            string accountId;
            iss >> accountId;
            res.push_back(to_string(bank.get_total_money_transaction_from(accountId)));
        } else if (queryType == "?inspect_cycle") {
            string accountId;
            int k;
            iss >> accountId >> k;
            res.push_back(to_string((bank.get_inspect_cycle(accountId, k))));
        }
    }

    for(auto x : res) cout << x << endl;

    return 0;
}