#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int val)
{
    if(s.empty()||s.top()<=val)
    {
        s.push(val);
    }
    else
    {
        int val1=s.top();
        s.pop();
        insert(s,val);
        s.push(val1);
    }
}
void sortAStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    else
    {
        int val=s.top();
        s.pop();
        sortAStack(s);
        insert(s,val);
    }
}

//sdfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff



int main()
{
    stack<int> ss;
    ss.push(5);
    ss.push(2);
    ss.push(4);
    ss.push(1);
    ss.push(3);
    sortAStack(ss);
    while(!ss.empty())
    {
        cout<<ss.top()<<" ";
        ss.pop();
    }




    return 0;
}
