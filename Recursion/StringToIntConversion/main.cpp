#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Input - "12345"
//Output - 12345
double stringToInt(char a[],double n)
{
    double num;
    if(n==0)
        return 0;
    else
    {
        num=a[0]-48;
        num*=pow(10,n-1);
        return num+stringToInt(a+1,n-1);
    }
}
int main()
{
    cout <<stringToInt("12345",5.0)<< endl;
    return 0;
}
