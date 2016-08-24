#include <iostream>

using namespace std;

int main()
{
    //since our problem size is small, we can simply "brute force" this problem
    int sum = 0, x1 = 1, x2 = 2, temp = 0;

    while( x2 <= 4000000 )
    {
        if(x2 % 2 == 0) //term is even
        {
            sum += x2;
        }

        temp = x2;//store x2
        x2 = x1 + x2; //find new x2

        x1 = temp;
    }

    cout<<sum<<endl;

    return 0;
}
