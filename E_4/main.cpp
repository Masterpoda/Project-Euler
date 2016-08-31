#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string palindrome, rev;
    int test, best = 0;

    for(int i = 999; i > 100 ; i--)
    {
        //iterating through 3 digit numbers.
        //this could be optimized by iterating diagonally along a combination chart
        for(int j = 999; j > 100; j--)
        {
            test = i*j;
            palindrome = to_string(test);

            rev = palindrome;

            reverse(palindrome.begin(), palindrome.end());

            if(rev == palindrome && best < test)
            {
               best = test;
            }
        }
    }

    cout << best << endl;

    return 0;
}


