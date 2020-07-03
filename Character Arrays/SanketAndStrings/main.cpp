#include <iostream>
/*
Sanket has a string consisting of only 'a' and 'b' as the characters.
Sanket describes perfectness of a string as the maximum length substring of equal characters.
Sanket is given a number k which denotes the maximum number of characters he can change.
Find the maximum perfectness he can generate by changing no more than k characters.

Input Format
The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.

Constraints
2 ≤ N ≤ 10^6

Output Format
A single integer denoting the maximum perfectness achievable.

Sample Input
2
abba
Sample Output
4
Explanation
We can swap the a's to b using the 2 swaps and obtain the string "bbbb". This would have all the b's and hence the answer 4.
Alternatively, we can also swap the b's to make "aaaa". The final answer remains the same for both cases.
*/
using namespace std;
int sanketAndStrings(char a[])
{
    int i=0;
    int j=1;
    int cur_len=1;
    int max_len=0;
    int flagl=0;
    int flagr=0;
    while(a[j]!='\0')
    {
        if(a[i]==a[j])
        {
            cur_len++;
            if(cur_len>max_len)
            {
                max_len=cur_len;
                flagl=i;
                flagr=j;
            }
            j++;
        }
        else
        {

            i=j;
            j++;
            cur_len=1;
        }
    }
    cout<<flagl<<flagr<<endl;
    if(flagl>0)
    {
        a[flagl-1]=a[flagl];
    }
    if(a[flagr+1]!='\0')
    {
        a[flagr+1]=a[flagr];
    }
    i=0;
    j=1;
    cur_len=1;
    max_len=0;
    flagl=0;
    flagr=0;
    while(a[j]!='\0')
    {
        if(a[i]==a[j])
        {
            cur_len++;
            if(cur_len>max_len)
            {
                max_len=cur_len;
                flagl=i;
                flagr=j;
            }
            j++;
        }
        else
        {

            i=j;
            j++;
            cur_len=1;
        }
    }
    return max_len;
}
int sanketAndStrings2(char a[],int k)
{
    int i=0;
    int j=1;
    int flag=0;
    int next=0;
    int cur_len=1;
    int max_len=0;
    int counter=k;
    while(a[j]!='\0')
    {
        cout<<a[j]<<"a[j]"<<endl;
        cout<<counter<<"counter"<<endl;
        cout<<a[i]<<"a[i]"<<endl;
        //cout<<next<<"next"<<endl;
        if(a[i]==a[j]||counter>0)
        {
            /*if(flag==0&&a[i]!=a[j])
            {
                flag=1;
                next=j;
            }*/
            cur_len++;
            if(cur_len>max_len)
            {
                max_len=cur_len;
            }
            if(a[i]!=a[j])
            {
                counter--;
            }
            j++;
        }
        else
        {
            i=i+1;
            j=i+1;
            cur_len=1;
            flag=0;
            counter=k;
        }
    }
    cout<<i<<endl;
    return max_len;

}
int sanketAndStrings3(char a[],int k)
{
    int counter=k;
    int i=0;
    int cur_len=0;
    int max_len=0;
    int flag=0;
    int rep=0;
    while(a[i]!='\0')
    {


        if(a[i]=='a'||counter>0)
        {
            cur_len++;
            if(a[i]!='a')
            {
                counter--;
                if(flag==0)
                {
                    flag=1;
                    rep=i;
                }
            }
            if(cur_len>max_len)
            {
                max_len=cur_len;
            }

            i++;
        }
        else
        {
            cur_len=0;
            i=rep+1;
            flag=0;
            counter=k;
        }
    }
    counter=k;
    i=0;
    cur_len=0;
    flag=0;
    rep=0;
    while(a[i]!='\0')
    {


        if(a[i]=='b'||counter>0)
        {
            cur_len++;
            if(a[i]!='b')
            {
                counter--;
                if(flag==0)
                {
                    flag=1;
                    rep=i;
                }
            }
            if(cur_len>max_len)
            {
                max_len=cur_len;
            }

            i++;
        }
        else
        {
            cur_len=0;
            i=rep+1;
            flag=0;
            counter=k;
        }
    }

    return max_len;
}
int main()
{
    int k;
    cin>>k;
    char a[1000000];
    cin>>a;
    cout<<sanketAndStrings3(a,k)<<endl;

    return 0;
}
