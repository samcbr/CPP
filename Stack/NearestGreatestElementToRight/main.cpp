#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Test case1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
*/

/*
Reference video - https://www.youtube.com/watch?v=NXOOYYwpbg4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=2
Approach
We are using stack data structure to improve the time complexity from o(n^2) to o(n).
Step 1 Start traversing the array arr from the end
Step 2 For every arr[i],check if the stack is empty
2.a if stack is not empty then check whether top element of stack is greater than arr[i], if it is so then push top in result vector and push arr[i] on stack else pop the top element until it becomes greater than arr[i] or stack becomes empty.
2.b if stack is empty or became empty then push -1 in result vector and push arr[i] on stack
Step 3 Reverse the result vector and print the same
*/
/*
    How we identified that stack could be used
    Hint1: This question had an array
    Hint2: In its naive solution the inner j loop was depending on i
    Naive solution -
    void greatestElementToRight(int a[],int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n-1;j++)    //NOTE how j is depending on i this is the biggest catch to know that stack can be used to optimize this solution
            {
                if(a[j]>a[i])
                {
                    cout<<a[j]<<" ";
                    break;
                }
            }
            if(j==n)
            {
                cout<<-1<<" ";
            }
        }
        cout<<-1<<" ";
    }
*/
vector<int> res;
vector<int> greatestElementToRight(int arr[],int n)
{
    stack<int> s;

    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty())
        {
            if(s.top()>arr[i])
            {
                res.push_back(s.top());
                s.push(arr[i]);
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
            s.push(arr[i]);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
int main()
{
    int a[]={1,3,0,0,1,2,4};
    vector<int> v=greatestElementToRight(a,7);
    for(int i=0;i<7;i++)
    {
        cout<<v[i];
    }
    return 0;
}
