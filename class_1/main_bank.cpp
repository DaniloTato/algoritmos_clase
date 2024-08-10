#include "include/bank.hpp"

int main(){
    bank b;
    b.add_acc("35", 465);
    b.print_acc_balance("35");
    b.add_balance("35", 50);
    b.print_acc_balance("35");
    b.add_balance("33", 50);


    return 0;
}