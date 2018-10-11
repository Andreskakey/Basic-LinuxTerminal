#include "Bank.h"
#include "stdlib.h"
void Bank::readAccts(){

       int response;

        cout << "Welcome to ABC Banking. Enter the Initial Accounts. " << endl;
        cout << "Enter 1 for a new account or any numbers key that isn't 1 or 0 to exit " << endl;
        cin >> response;

	if (response >= 2){
	exit(1);
}

       while(response){

           newAcct();
           cout<< "Enter 1 for a new account, 0 to quit: " << endl;
           cin >> response;

       }
   }
   void Bank::newAcct(){

    int an, at;
    double b;
    string fn, ln;
    string ssn;
            cout << "Enter Account Number." << endl;
            cin >> an;

/* Search For Account */
        int pos = find(an);

            if (pos >= 0){

                cout << "Error! Account already exists." << endl;
                return ;

       }

            else{

        /* Call Typemenu() Function */

                cout << "Enter Your First Name." << endl;
                cin >> fn;
                cout << "Enter Your Last Name." << endl;
                cin >> ln;
                cout << "Enter Your SSN." << endl;
                cin >> ssn;
                typemenu();
                cout << "Enter the Account type you want to open." << endl;
                cin >> at;

                cout << "Enter the initial deposit." << endl;
                cout << "$";
                cin >> b;


             /* Dynamically Allocate new Accounts */
           acct [numaccts++] = new Account (an,at,b,fn,ln,ssn);

       }
   }

