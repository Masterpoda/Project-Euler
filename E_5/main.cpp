#include <iostream>

using namespace std;

int main()
{

    int sumofsquares = 0, squareofsums = 0;

    //while there is likely a simpler algebraic solution,
    //this problem is well within reason to solve via for loop
    for(int i = 0; i <= 100 ; i++)
    {
        sumofsquares += i*i;
        squareofsums += i;
    }

    squareofsums *= squareofsums;

    cout << squareofsums - sumofsquares << endl;

    return 0;
}


