#include <iostream>

using namespace std;

int main()
{   

    long long n = 1, k = 1;
    int grid = 2;

    //the proof for this problem is difficult to see in code, since it is mostly geometric
    //basically the result is a binomial coefficient of n*2 choose n
    //unfortunately at the time of writing this, Bignum is incapable of mutiplication
    //this means computing 40 factorial is outside the range of values we can hold
    //I will return to this problem when Bignum can handle it, in the mean time we can use
    //wolfram alpha to reveal the answer is 137846528820

    for(int i = grid*2; i >= grid/2; i--)
    {
        n *= i;
    }



    for(int i = 1; i <= grid; i++)
    {

        k *= i;
    }
    cout << n << endl;
    cout << k << endl;
    cout << n/k << endl;

    return 0;
}
