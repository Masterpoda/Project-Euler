#ifndef BIGNUM_H
#define BIGNUM_H

#include <vector>
#include <climits>
#include <cmath>
//#include <tgmath.h>
#include <iostream>
#include <string>

using namespace std;

class Bignum {

    public:
    Bignum(){}
    ~Bignum()
    {
        holder.clear();
    }

    vector<unsigned int> holder;    //holding vector for "digits" of a base 9999 number
    bool positive = true;           //sign bit
    void print();                   //print numeric value
    void held();                    //print space-separated contents of holder
    string getstring();             //returns a string with the number's value
    unsigned long long size();      //Returns the number of digits in the number


    Bignum operator + (Bignum rhs);
    Bignum operator += (Bignum rhs);
    Bignum operator * (Bignum rhs);
    bool operator > (Bignum rhs);
    bool operator < (Bignum rhs);
    bool operator >= (Bignum rhs);
    bool operator <= (Bignum rhs);
    bool operator == (Bignum rhs);
    //Bignum operator - (Bignum rhs);
    Bignum operator + (const unsigned long long rhs);
    Bignum operator = (Bignum rhs);
    Bignum operator = (const unsigned long long rhs);
    Bignum operator = (string rhs);
};

Bignum Bignum::operator + (Bignum rhs)
{
    unsigned int size = 0;
    unsigned long long carry = 0, temp = 0;
    int diff = 0;
    vector<unsigned int> result;

    if(holder.size() == rhs.size())
    {
        size = holder.size() + 1;
    }
    else if(holder.size() > rhs.size())
    {
        size = holder.size() + 1;
    }
    else
    {
        size = rhs.size() +1 ;
    }

    //cout<<"Result size: "<<size<<endl;

    result.resize(size);
    diff = abs((int)holder.size() - (int)rhs.holder.size());
    //cout<<"diff is: "<<diff<<endl;

    for(int i = size-2; i >= 0; i--)
    {
        if(holder.size() >= rhs.holder.size())
        {

            if(i - diff < 0)
            {
                temp = holder[i] + carry;
            }
            else
            {
                temp = holder[i] + rhs.holder[i - diff] + carry;
            }

            if(temp <= 9999)
            {
                result[i] = temp;
                carry = 0;
            }
            else
            {
                result[i] = (temp) % 10000;
                carry = 1;
            }
        }
        else
        {
            if(i - diff < 0)
            {
                temp = rhs.holder[i] + carry;
                //cout<<"x"<<endl;
            }
            else
            {
                temp = holder[i - diff] + rhs.holder[i] + carry;
                //cout<<"y"<<endl;
            }
            //cout<<"Temp is "<<temp<<endl;

            if(temp <= 9999)
            {
                result[i] = temp;
                carry = 0;
            }
            else
            {
                result[i] = (temp) % 10000;
                carry = 1;
            }
        }


    }

    if(result.back() == 0)
        result.pop_back();


    holder = result;

    return *this;
}

Bignum Bignum::operator += (Bignum rhs)
{
    holder = (rhs + *this).holder;

    return *this;
}



Bignum Bignum::operator * (Bignum rhs)
{
    unsigned int num1size, num2size;
    vector<Bignum> multiples;
    Bignum sum, multiple; //sum holds the sum of the multiples
    vector<unsigned int>::iterator it;

    num1size = holder.size();

    num2size = rhs.size();



    for(int i = num1size - 1; i >= 0; i--)
    {
        for(unsigned int j = 0; j < num2size; j++)
        {
            cout<<"multiplying "<<holder[i]<<" by "<< rhs.holder[j];
            multiple = holder[i]*rhs.holder[j];
            //append zeros to multiple ERROR HERE
            for(unsigned int k = 0; k < num1size - (i + 1); k++)
            {
                multiple.holder.push_back(0);
            }
            cout<< "multiple "<< j+1 << " is ";
            multiple.held();
            multiples.push_back(multiple);
        }

        //sum them up here
        for(unsigned int k = 0; k < multiples.size(); k++)
        {

            cout<<"Sum before add is: ";
            sum.held();
            sum = sum + multiples[k];
            cout<<"Sum after add is: ";
            sum.held();
        }
        multiples.clear();

    }
    cout<<endl;


    holder = sum.holder;

    return *this;
}



/*
Bignum Bignum::operator - (Bignum rhs)
{
    unsigned int size;
    unsigned long long carry = 0;
    vector<unsigned int> result;


    return *this;
}
*/

bool Bignum::operator > (Bignum rhs)
{
    int i = 0;
    if(holder.size() > rhs.size())
    {
        i = holder.size();
        rhs.holder.resize(i);
    }
    else
    {
        i = rhs.size();
        holder.resize(i);
    }


    for(; i >= 0; i--)
    {
        if(holder[i] > rhs.holder[i])
            return true;
        else if(holder[i] < rhs.holder[i])
            return false;
    }

    return false;//if we reach the end, they are equal, thus false.
}

bool Bignum::operator >= (Bignum rhs)
{
    int i = 0;
    if(holder.size() > rhs.size())
    {
        i = holder.size();
        rhs.holder.resize(i);
    }
    else
    {
        i = rhs.size();
        holder.resize(i);
    }


    for( ; i >= 0; i--)
    {
        if(holder[i] > rhs.holder[i])
            return true;
        else if(holder[i] < rhs.holder[i])
            return false;
    }

    return true;//if we reach the end, they are equal, thus true.
}

bool Bignum::operator < (Bignum rhs)
{
    int i = 0;
    if(holder.size() > rhs.size())
    {
        i = holder.size();
        rhs.holder.resize(i);
    }
    else
    {
        i = rhs.size();
        holder.resize(i);
    }


    for( ; i >= 0; i--)
    {
        if(holder[i] < rhs.holder[i])
            return true;
        else if(holder[i] > rhs.holder[i])
            return false;
    }

    return false;//if we reach the end, they are equal, thus false.
}

bool Bignum::operator <= (Bignum rhs)
{
    int i = 0;
    if(holder.size() > rhs.size())
    {
        i = holder.size();
        rhs.holder.resize(i);
    }
    else
    {
        i = rhs.size();
        holder.resize(i);
    }


    for( ; i >= 0; i--)
    {
        if(holder[i] < rhs.holder[i])
            return true;
        else if(holder[i] > rhs.holder[i])
            return false;
    }

    return true;//if we reach the end, they are equal, thus true.
}

bool Bignum::operator == (Bignum rhs)
{
    int i = 0;
    if(holder.size() > rhs.size())
    {
        i = holder.size();
        rhs.holder.resize(i);
    }
    else
    {
        i = rhs.size();
        holder.resize(i);
    }


    for( ; i >= 0; i--)
    {
        if(holder[i] != rhs.holder[i])
            return false;
    }

    return true;//if we reach the end, they are equal, thus true.
}



Bignum Bignum::operator + (const unsigned long long rhs)
{
    //vector<unsigned int> result;

    Bignum holder2, copy;

    holder2 = rhs;

    *this = copy + holder2;

    return *this;
}

Bignum Bignum::operator = (Bignum rhs)
{
    holder = rhs.holder;
    positive = rhs.positive;
    return *this;
}

Bignum Bignum::operator = (string rhs)
{

    int iters;//calculate how many times we need to parse 4 digits
    int size = rhs.length();

    if(size %4 == 0)
        iters = size/4;
    else
        iters = size/4 + 1;

    holder.clear();
    holder.resize(iters);



    if(rhs[0] == '-')
    {
        positive = false;
        rhs.erase(0,1);
    }


    for(int i = 0; i < iters; i++)
    {
        if(size - (i+1)*4 >= 0)
            holder[iters - (i+1)] = stoi(rhs.substr((size - (i + 1)*4), 4));//adding 4 digits at a time. THROWS EXCEPTION
        else
            holder[iters - (i+1)] = stoi(rhs.substr(0, size % 4));//adding the rest of the string.
    }

    return *this;
}


//mistake here
Bignum Bignum::operator = (const unsigned long long rhs)
{
    string newval;
    newval = to_string(rhs);
    int size = newval.length();
    int iters;

    //calculate how many times we need to parse 4 digits
    if(size %4 == 0)
        iters = size/4;
    else
        iters = size/4 + 1;

    if(rhs < 0)
        positive = false;

    holder.clear();
    holder.resize(iters);


    for(int i = 0; i < iters; i++)
    {
        if(size - (i+1)*4 >= 0)
        {
            holder[iters - (i+1)] = stoi(newval.substr((size - (i + 1)*4), 4));//adding 4 digits at a time. THROWS EXCEPTION
        }
        else
        {
            holder[iters - (i+1)] = stoi(newval.substr(0, size % 4));//adding the rest of the string.
        }
    }
    cout<<endl;

    return *this;
}

void Bignum::print()
{
    for(unsigned int i = 0; i < holder.size(); i++) //printing out each
    {
        if(i != 0) //dont need leading zeros if we're at the leading digit
        {
            if(holder[i]< 10)
                cout<<"000";
            else if ( holder[i]< 100)
                cout<<"00";
            else if ( holder[i]< 1000)
                cout<<"0";
        }

        cout<<holder[i];
    }
    cout<<endl;
}

//Displays contents of holder
void Bignum::held()
{
    for(unsigned int i = 0; i< holder.size(); i++)
    {
        cout<<holder[i]<< "  ";
    }
    cout<<endl;
}

unsigned long long Bignum::size()
{
    return holder.size();
}

string Bignum::getstring()
{
    string stringholder = "";

    if(!positive)
        stringholder = "-";

    for(unsigned int i = 0; i < holder.size(); i++)
    {
        stringholder.append(to_string(holder[i]));
    }

    return stringholder;
}

#endif
