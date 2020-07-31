#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> res;
vector<int> nearestSmallerElementToLeft(int a[],int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty())
        {
            if(s.top()<a[i])
            {
                res.push_back(s.top());
                s.push(a[i]);
                break;
            }
            else
            {
                s.pop();
            }
        }
        if(s.empty())
        {
            res.push_back(-1);
            s.push(a[i]);
        }
    }
    return res;
}
int main()
{
    int a[]={1,2,0,0,2,4};
    vector<int> v=nearestSmallerElementToLeft(a,6);
    for(int i=0;i<6;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
