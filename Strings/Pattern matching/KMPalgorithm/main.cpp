#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void kmp(char *str,char *pat)
{
    int n=strlen(str);
    int m=strlen(pat);
    int lps[m];
    int j=1;
    int i=0;
    lps[i]=0;
    while(j<m)
    {
        if(pat[i]==pat[j])
        {
            lps[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=0;
            }

            else
            {
                lps[j]=0;
                j++;
            }
        }
    }
    i=0;
    j=0;
    while(i<n)
    {
        if(j<m)
        {
            if(pat[j]==str[i])
            {
                i++;
                j++;
            }
            else
            {
                if(j>0)
                    {
                        j=lps[j-1];
                    }
                else
                    {
                        i++;
                    }
            }
        }
        else
        {
            cout<<i-j<<endl;
            j=lps[j-1];     //vvi This is done to handle the case of overlapping pattern
        }

    }
    if(j==m)
    {
        cout<<i-j<<endl;
    }

}
int main()
{
    kmp("aaaaaaaaa","aaa");
    return 0;
}
