#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> res;
vector<int> nearestGreaterElementToLeft(int a[],int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty())
        {
            if(s.top()>a[i])
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
            s.push(a[i]);
            res.push_back(-1);
        }
    }
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    int a[]={1,3,2,4};
    vector<int> v=nearestGreaterElementToLeft(a,4);
    for(int i=0;i<4;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
