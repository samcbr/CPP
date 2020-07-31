#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
bool backspaceCompare(string S, string T) {
        int j;
        for(int i=1;i<S.length();i++)
        {
            if(S[i]=='#')
            {
                S[i]='1';
                j=i-1;
                while(j>=0)
                {
                    if(S[j]!='1')
                    {
                        S[j]='1';
                        break;
                    }
                    j--;
                }
            }
        }
        for(int i=1;i<T.length();i++)
        {
            if(T[i]=='#')
            {
                j=i-1;
                T[i]='1';
                while(j>=0)
                {
                    if(T[j]!='1')
                    {
                        T[j]='1';
                        break;
                    }
                    j--;
                }
            }
        }
        j=0;
        cout<<S<<endl;
        cout<<T<<endl;
        for(int i=0;i<S.length();i++)
        {
            if((S[i]!='1'&&S[i]!='#'))
            {
                cout<<S[i]<<endl;
                while((T[j]=='1'||T[j]=='#')&&j<T.length())
                {
                    j++;
                }
                cout<<i<<endl;
                cout<<j<<endl;
                if(j==T.length())
                    return false;
                if(T[j]!=S[i])
                {
                    return false;
                }
                j++;
            }
        }
        if(j<T.length())
        {
            return false;
        }

        return true;
    }
    bool backspaceCompare2(string S, string T) {
        stack<int> s1;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='#')
            {
                if(!s1.empty())
                {
                    s1.pop();
                }
            }
            else
                s1.push(S[i]);
        }
        int j=0;
        S="";
        while(!s1.empty())
        {
            S+=s1.top();
            s1.pop();
            j++;
        }
        S[j]='\0';
        for(int i=0;i<T.length();i++)
        {
            if(T[i]=='#')
            {
                if(!s1.empty())
                {
                    s1.pop();
                }
            }
            else
                s1.push(T[i]);
        }
        j=0;
        T="";
        while(!s1.empty())
        {
            T+=s1.top();
            s1.pop();
            j++;
        }
        T[j]='\0';
        cout<<S<<endl;
        cout<<T<<endl;
        if(S==T)
        {
            return true;
        }
        else
            return false;
    }
bool backspaceCompare3(string S,string T)
{
    int count1=0;
    int count2=0;
    int i=0;
    int j=T.length()-1;
    for(i=S.length()-1;i>=0;i--)
    {
        if(S[i]=='#')
        {
            count1++;
        }
        else
        {
            if(count1>0)
            {
                count1--;
                if(count1==0)
                {
                    continue;
                }
            }
        }
        if(count1==0)
        {
            while(S[j]!='#')
            {
                if(count2==0)
                {

                }
            }
        }

    }
}
int main()
{
    string S="hii";
    S="";
    cout<<S<<endl;
    cout <<backspaceCompare2("a#c","b")<< endl;
    return 0;
}


