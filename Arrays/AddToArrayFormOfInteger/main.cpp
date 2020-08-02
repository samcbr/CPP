#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.



Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000


Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/

vector<int> addToArrayForm(vector<int>& A, int k)
{
        static vector<int> res;
        int i=A.size()-1;
        int dig;
        int carry=0;
        while(k>0&&i>=0)
        {
            dig=k%10;
            if((A[i]+dig+carry)<10)
            {
                res.push_back(A[i]+dig+carry);
                carry=0;
            }
            else
            {
                res.push_back((A[i]+dig+carry)-10);
                carry=1;
            }
            k=k/10;
            i--;
        }
        while(k>0)
        {
            dig=k%10;
            if((dig+carry)<10)
            {
                res.push_back(dig+carry);
                carry=0;
            }
            else
            {
                res.push_back(dig+carry-10);
                carry=1;
            }
            k=k/10;
        }
        while(i>=0)
        {
            if((A[i]+carry)<10)
            {
                res.push_back(A[i]+carry);
                carry=0;
            }
            else
            {
                res.push_back(A[i]+carry-10);
                carry=1;
            }
            i--;
        }
        if(carry==1)
        {
            res.push_back(carry);
        }
        reverse(res.begin(),res.end());
        return res;
}
int main()
{
    vector<int> s;
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    vector<int> res=addToArrayForm(s,1);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i];
    }
    return 0;
}
