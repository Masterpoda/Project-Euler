#include <iostream>
#include "bignum.h"
using namespace std;

int main()
{
    //a series of tests to confirm bignum is working
    Bignum n1, n2, n3, n4;
    n1 = 174312;
    n2 = 2;

    cout<<"N1 is ";
    n1.held();

    cout<< "N2 is ";
    n2.held();

    n1 = n2 * n1;

    n1.print();
    cout<<174312*2<<endl;

    return 0;
}
