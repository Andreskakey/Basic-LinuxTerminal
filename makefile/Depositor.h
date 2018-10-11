#include "Name.h"
class Depositor
{

    private:

        Name myname;
        string ssn;

     public:
         void setName(string fname, string lname)
         {
            myname.setFirst(fname);
            myname.setLast(lname);
         }
         void setSsn(string s)
         {
            ssn=s;
         }
         string getName()
         {
             return myname.getFirst() + " " + myname.getLast();
         }
         string getSsn()
         {
            return ssn;
         }
};
