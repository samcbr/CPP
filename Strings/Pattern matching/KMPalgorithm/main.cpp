#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void kmp1(char str[],char pat[])
{
    int n=strlen(str);
    int m=strlen(pat);

    int i=0;
    int j=1;

    //First we will pre process the pattern and create lps array for the same
    int lps[m];//lps array will have same size as pattern length
    lps[i]=0;
    while(j<m)
    {
        if(pat[i]==pat[j])
        {
            i++;
            lps[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=lps[i-1];     // Dry run this pattern to understand the reason for this step "ABAAABAAB"
                                //lps array for above pattern should be {0,0,1,1,1,2,3,4,2}
            }
            else//i=0
            {
                lps[j]=i;
                j++;
            }
        }
    }

    //Now we will find the pattern in string and print index of the pattern in string
    j=0;    //used for traversing the string
    i=0;    //used for traversing the string

    //In this while loop we never backtrack i instead we only backtrack j when there is a mismatch
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
                if(j!=0)
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
            j=lps[j-1];     //This is specifically done to handle overlapping pattern in string
        }
    }
    if(j==m)
    {
        cout<<i-j<<endl;
    }

}
int main()
{
    kmp1("aaaabaaaa","aaa");
    return 0;
}
