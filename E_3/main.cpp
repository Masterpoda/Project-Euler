#include <iostream>
#include <tgmath.h>

using namespace std;

int main()
{
    //since our problem size is small, we can simply "brute force" this problem
    long long best = 0;


    best = 600851475143;

    //this method is similar to the sieve of ertotosthenes
    for (int i = 2; i < best; i++)
    {
        while(best % i == 0 )
        {
            best /= i;
        }
    }

    cout<<best<<endl;

    return 0;
}


