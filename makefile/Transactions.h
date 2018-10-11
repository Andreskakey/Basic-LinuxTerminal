//Transactions.h

#include<iostream>
#include<string.h>
    using namespace std;

class Transaction
{

    private:

        int ttype;
        double amt;

    public:

/* Mutator Function for Transaction Class */
void setTrans(int t, double a){

        ttype =t;
        amt = a;

    }

/* Print Transactions Corresponding to Transaction Type (ttype) */
void prt(){

        string message;

        if (ttype == 0)
           message = "Account Opened.";
        else

           if (ttype == 1)
               message = "Deposit.";
           else

               if (ttype == 2)
                   message = "Withdrawal.";
               else

                   if (ttype == 3)
                       message = "Account Closed.";
        cout << message << " " << amt << endl;

    }
};
