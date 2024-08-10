#ifndef hola
#define hola

#include <iostream>


class bank{
public:
    void add_acc(std::string account_num, double initial_balance);
    double get_acc_balance(std::string account_num);
    void add_balance(std::string account_num, double to_sum);
    void print_acc_balance(std::string account_num);
    void substract_balance(std::string account_num, double to_sum);
private:
    struct _bank_account{
        std::string account_num;
        double balance;

    };

    std::vector<_bank_account> _accounts;

    int find_account_index(std::string account_num);

};

#endif