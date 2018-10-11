//main function
#include "Bank.h"
int main()
{
    Bank myBank;
    myBank.readAccts();
    myBank.processTransactions();
    myBank.printAllAccts();
    return 0;
}
