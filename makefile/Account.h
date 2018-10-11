//Account.h

#include "Transactions.h"
#include "Depositor.h"
#include <iostream>

class Account{

    private:

        int acctnum;
        int ntrans;
        double bal;
        Transaction * tr;                                                  // dynamic allocation of Transaction class
        int status;
        int acctype;
        Depositor dep;

     public:

/* Account Constructor: initialize all Account variables */
Account (int an,int at,double b, string fn, string ln, string ssn){                                              // an = a number

            string kind[3] = {"Checking ", "Savings ", "Money Market "};
            acctnum = an;
            bal = b;
            ntrans = 0;
            tr = new Transaction [10];                                                  // set up new array of transaction
            tr[ntrans].setTrans(0, bal);
            status = 1;
            acctype = at-1;
            dep.setSsn(ssn);
            dep.setName(fn,ln);
            cout << "Congratulations  " << dep.getName() << endl;
            cout << "You have opened a new " << kind[at-1] << "account" << endl;
            cout << "Initial balance: $" << b << endl;
            ntrans++;

        }

/* Destructor for the Account Constructor */
~Account(){

        delete[] tr;
     }

/* Mutator Function for retrieving private member variable status */
int getStatus(){

         return status;
     }
string getName()
{
    return dep.getName();
}
string getSsn()
{
    return dep.getSsn();
}
/* Mutator Function for retrieving private member variable type */
int getType(){

         return acctype;
     }

/* Mutator Function for retrieving private member variable acctnum */
int getAcctnum(){

         return acctnum;
     }

/* Account: Deposit Function */
void deposit(){

    double amt;

         cout << "How much do you want to deposit" << endl;
         cin >> amt;

         bal += amt;
         tr[ntrans++].setTrans(1,amt);

         cout << "You have deposited " << amt << " and now have a balance of $" << bal << endl;

     }

/* Account: Withdrawal Function */
void withdrawal(){

    double amt;

         cout << "How much do you want to withdraw?" << endl;
         cin >> amt;

         if (amt <= bal)
         {
             bal -= amt;
             tr[ntrans++].setTrans(2,amt);
             cout << "You have withdrawn " << amt << " and now have a balance of $" << bal << endl;
         }

         else
         cout << "Error: Insufficient Funds." << endl;

     }

/* Account: Close Account Function */
void closeAcct(){

         status = 0;
         cout << dep.getName()<<endl;
         cout << "Your Account is now closed. "<< dep.getName()<<endl;
         cout << "Here are your funds of " << bal <<endl;

         tr[ntrans++].setTrans(3,bal);
         bal = 0;

     }

/* Account: Inquiry Function */
void inquiry(){
         cout << dep.getName()<<endl;
         cout << "Your current balance is $" << bal <<endl;

         prtTrans();

     }

/* Account: Print Transaction */
void prtTrans(){

         cout << "Here are your transactions: " << endl;

         for (int i = 0; i < ntrans; i++){

             cout<< i+1 <<": ";
             tr[i].prt();
         }
     }


/* Account: Re-open */
void reopen(){

         status = 1 ;

         tr[ntrans++].setTrans(4,bal);

         cout << "Your Accountt is now reopened." << endl;
     }
 };
