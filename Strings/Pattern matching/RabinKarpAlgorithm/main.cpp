#include <iostream>
#include <bits/stdc++.h>
#define a 13
#define ll long long int
using namespace std;
void rabinKarpSearch(string pat,string str)
{
    ll patHash=0;
    ll strHash=0;
    int j=0;
    for(int i=0;i<pat.length();i++)
    {
        patHash+=pow(a,i)*pat[i];
        strHash+=pow(a,i)*str[i];
    }

    for(int i=0;i<=(str.length()-pat.length());i++)
    {

        if(patHash==strHash)
        {
            for(j=0;j<pat.length();j++)
            {
                if(pat[j]!=str[i+j])
                {
                    break;
                }
            }
            if(j==pat.length())
            {
                cout<<i<<endl;
            }
            j=0;
        }
        strHash=(strHash-str[i])/a+pow(a,pat.length()-1)*str[i+pat.length()];     //calculating next hash using current hash

    }
}
int main()
{
    rabinKarpSearch("am","shubham");
    return 0;
}
