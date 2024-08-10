#include "../include/bank.hpp"

void bank::add_acc(std::string account_num, double initial_balance){
    _bank_account new_account;
    new_account.account_num = account_num;
    new_account.balance = initial_balance;
    _accounts.push_back(new_account);
}

double bank::get_acc_balance(std::string account_num){
    int response = find_account_index(account_num);
    if (response != -1){
        return _accounts[response].balance;
    }

    return 0;

}

void bank::add_balance(std::string account_num, double to_sum){
    int response = find_account_index(account_num);
    if (response != -1){
        _accounts[response].balance += to_sum;
    }

}

void bank::substract_balance(std::string account_num, double to_sum){
    int response = find_account_index(account_num);
    if (response != -1){
        _accounts[response].balance -= to_sum;
    }

}

int bank::find_account_index(std::string account_num){
    for (int i = 0; i < _accounts.size(); i++){
        if (_accounts[i].account_num == account_num){
            return i;
        }
    }

    std::cout << "account " << account_num << " not found" << "\n";
    return -1;
}

void bank::print_acc_balance(std::string account_num){
    std::cout << "my balance: " << get_acc_balance(account_num) << "\n";
}