#include <iostream>
#include <list>

using namespace std;

int main()
{

    list<long long> primeList = {}; //a list containing all primes found so far
    long long value = 2;            //value to be tested
    bool isPrime = true;


    //this method should work well for finding an nth prime,
    //but not necessarily for testing primality
    while(primeList.size() < 10001)
    {
        isPrime = true;
        for(auto i : primeList)
        {
            if(value % i == 0)//if our values can be divided by a previous prime
                isPrime = false;
        }

        //add to our prime list
        if(isPrime)
        {
            primeList.push_back(value);
        }
        value++;
    }


    cout << value - 1 << endl;

    return 0;
}
