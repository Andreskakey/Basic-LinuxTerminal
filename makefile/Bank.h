//Bank.h
#include "Account.h"
#include <iostream>
int const MAX_NUM=100;
class Bank{

    private:

       Account * acct[MAX_NUM];
       int numaccts;
       int nopen, nclosed;
    public:

/* Bank Constructor: initialize all Bank variables */
Bank(){

           nopen = nclosed = numaccts = 0;

       }

/* Destructor for the Bank Constructor */
~Bank(){

           for(int i = 0; i < numaccts; i++){
              delete acct[i];
           }

       }

/* Bank: Read Accounts Function */
void readAccts();
/*located in bank cpp */
/* Bank: Find Account Function */
int find(int an){

       for (int i = 0; i < numaccts; i++)
           if (acct[i]->getAcctnum() == an)
                return i;
           return -1;

   }

/* Bank: New Account Function */
void newAcct(); /* bank cpp */


/* Bank: Deposit Function */
void deposit(){

    int an;

        cout << "Enter your Account number." << endl;
        cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout << "Account not found." << endl;
           return;

       }

       if (acct[pos]->getStatus()== 0){

           cout << "Account was closed." << endl;
           return;

       }

       acct[pos]->deposit();

 }

/* Bank: Withdrawal Function */
void withdrawal(){

    int an;

       cout << "Enter your Account number." << endl;
       cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout << "Account not found." << endl;
           return;

       }

       if (acct[pos]->getStatus()== 0){

           cout << "Account was closed." << endl;
           return;

       }

       acct[pos]->withdrawal();

   }

/* Bank: Inquiry Funtion */
void inquiry(){

    int an;

       cout << "Enter your Account Number." << endl;
       cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout << "Account not found." << endl;
           return;

       }

       if (acct[pos]->getStatus()== 0){

           cout << "Account was closed." << endl;
           return;

       }

       acct[pos]->inquiry();

   }

/* Bank: Process Transactions Function */
void processTransactions(){

    char choice;
    menu();
    cin >> choice;

    while (choice != 'Q' && choice != 'q'){


        switch(choice){
            case 'W':
            case 'w':
                withdrawal();
                break;
            case 'D':
            case 'd':
                deposit();
                break;
            case 'B':
            case 'b':
                inquiry();
                break;
            case 'I':
            case 'i':
                printInfo();
                break;

            case 'H':
            case 'h':
               printAllAccts();
                break;

            case 'N':
            case 'n':
                newAcct();
                break;
            case 'C':
            case 'c':
                closeAcct();
                break;
            case 'R':
            case 'r':
                reopenAcct();
                break;
            case 'X':
            case 'x':
                deleteAcct();
                break;
            case 'Q':
            case 'q':
                printAllAccts();                                                                     //PRINT ACCOUNT ARRAY
                cout << "Thank You for using VR&Co Banking. Please come again!" << endl;
                break;
            default:
                cout << "That is not a valid selection. Please select another choice." << endl;
        }
            menu();
            cin >> choice;
       }
   }

/* Bank: Menu Function */
void menu(){

       /* menu print goes here */
    cout << "\t***************" << endl;
    cout << "\t   Bank Menu" << endl;
    cout << "\t W - Withdraw" << endl;
    cout << "\t D - Deposit"  << endl;
    cout << "\t I - Account Info (without transaction history)"  << endl;
    cout << "\t H - Account Info plus Account Transaction History"  << endl;
    cout << "\t N - New Account"  << endl;
    cout << "\t C - Close Account"  << endl;
    cout << "\t R - Reopen Account"  << endl;
    cout << "\t X - Delete Account"  << endl;
    cout << "\t B - Balance" << endl;
    cout << "\t Q - Quit" << endl;
    cout << "\t**************" << endl;
    cout << endl;

    cout<<"Enter choice now: " <<endl;

   }
/* Bank: Type Menu Function */
void typemenu(){

    cout << "\t***************" << endl;
    cout << "\t   Type Menu" << endl;
    cout << "\t 1 - Checking" << endl;
    cout << "\t 2 - Savings"  << endl;
    cout << "\t 3 - Money Market"  << endl;
    cout << "\t**************" << endl;
    cout << endl;

}

void  printInfo(){
int ans;
cout << "Here are your Account information Without the Transaction: " << endl;
cout << "Enter the account  number " << endl;

cin>>ans;

  int pos = find(ans);

       if (pos < 0){
           cout << "Account not found." << endl;
           return;
       }
   string kind[3] = {"Checking ", "Savings ", "Money Market "};
    cout<< "Account Number " << acct[pos]->getAcctnum() << endl;
         cout<< "SSN " << acct[pos]->getSsn() << endl;
         cout << "Type of account: " << kind[acct[pos]->getType()]<<endl;
            if (acct[pos]->getStatus()== 0)
                cout << "Account was closed." << endl;
            else
                acct[pos]->inquiry();
}
/* Bank: Print All Accounts Function */
void printAllAccts(){

      string kind[3] = {"Checking ", "Savings ", "Money Market "};

      cout << "Here is the information on all accounts:" << endl;

      for(int i = 0; i < numaccts; i++){
         cout<< "Account Number " << acct[i]->getAcctnum() << endl;
         cout<< "SSN " << acct[i]->getSsn() << endl;
         cout << "Type of account: " << kind[acct[i]->getType()]<<endl;

            if (acct[i]->getStatus()== 0)
                cout << "Account was closed." << endl;
            else
                acct[i]->inquiry();
      }
   }
   /* Close Account function */
void closeAcct(){

    int an;

       cout << "Enter your Account number." << endl;
       cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout<< "Account not found." << endl;
           return;
       }

       if (acct[pos]->getStatus()== 0){

           cout << "Account is already closed!" << endl;
           return;

       }

       acct[pos]->closeAcct();

   }

   /* Reopen Account function */
void reopenAcct(){

    int an;

       cout << "Enter your Account number." << endl;
       cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout<< "Account not found." << endl;
           return;
       }

       if (acct[pos]->getStatus()== 1){

           cout << "Account is already open!" << endl;
           return;

       }

       acct[pos]->reopen();

   }





/* Bank: Delete Account Function */
void deleteAcct(){

    int an;

       cout << "Enter your Account number." << endl;
       cin >> an;

/* Search For Account */
    int pos = find(an);

       if (pos < 0){

           cout<< "Account not found." << endl;
           return;
       }

       if (acct[pos]->getStatus()== 1){

           cout << "Account must be closed before deletion." << endl;
           return;

       }

       cout << "You have successfully deleted account." << acct[pos]->getAcctnum() << endl;

            delete acct[pos];
            numaccts--;

       for (int i = pos; i < numaccts; i++)
           acct[i] = acct[i+1];

   }

};
