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

    vector<unsigned int> holder; //holding vector for "digits" of a base 9999 number
    bool positive = true; // sign bit
    void print(); //print
    string getstring(); //returns a string with the number's value
    unsigned long long size();

    Bignum operator + (Bignum rhs);
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
    unsigned int size;
    unsigned long long carry = 0;
    vector<unsigned int> result;

    if(holder.size() > rhs.size())
    {
        size = holder.size();
        rhs.holder.resize(size);//makes adding simpler
    }
    else
    {
        size = rhs.size();
        holder.resize(size);//makes adding simpler
    }

    result.resize(size);

    for(unsigned int i = 0; i < result.size(); i++)
    {
        if(holder[i] + rhs.holder[i] + carry <= 9999)
        {
            result[i] = holder[i] + rhs.holder[i] + carry;
            carry = 0;
        }
        else
        {
            result[i] = (holder[i] + rhs.holder[i] + carry) % 9999;
            carry = 1;
            if(i == result.size())
                result.push_back(0);
        }
    }


    holder = result;

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

    int iters = rhs.length()/4 + 1;//calculate how many times we need to parse 4 digits

    holder.clear();
    holder.resize(iters);

    int size = rhs.length();

    if(rhs[0] == '-')
    {
        positive = false;
        rhs.erase(0,1);
    }


    for(int i = 0; i < iters; i++)
    {
        if(size - i*4 > 0)
            holder[i] = stoi(rhs.substr(i*4, 4));//adding 4 digits at a time.
        else
            holder[i] = stoi(rhs.substr(i*4));//adding the rest of the string.
    }

    return *this;
}

Bignum Bignum::operator = (const unsigned long long rhs)
{
    string newval;
    newval = to_string(rhs);
    int iters = (floor(log10(rhs)))/4 + 1;//calculate how many times we need to parse 4 digits

    if(rhs < 0)
        positive = false;

    holder.clear();
    holder.resize(iters);

    int size = newval.length();


    for(int i = 0; i < iters; i++)
    {
        if(size - i*4 > 0)
            holder[i] = stoi(newval.substr(i*4, 4));//adding 4 digits at a time.
        else
            holder[i] = stoi(newval.substr(i*4));//adding the rest of the string.
    }

    return *this;
}

void Bignum::print()
{
    for(unsigned int i = 0; i < holder.size(); i++) //printing out each
    {
        cout<<holder[i];
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
