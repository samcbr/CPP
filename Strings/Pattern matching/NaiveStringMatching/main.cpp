#include <iostream>
#include<string>
using namespace std;
void naiveStringMatch(string s,string pattern)
{
    int j=0;
    for(int i=0;i<=s.length()-pattern.length();i++)
    {
        while(j<pattern.length())
        {
            if(pattern[j]!=s[i+j])
            {
                j=0;
                break;
            }
            j++;
        }
        if(j==pattern.length())
        {
            cout<<i<<endl;
        }
        j=0;
    }
}

int main()
{
    naiveStringMatch("aaabaaabaaaab","aab");
    long long int a='1';
    cout<<a;
    return 0;
}
