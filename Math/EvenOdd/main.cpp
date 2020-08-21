#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
Problem Description
In this even odd problem Given a range [low, high] (both inclusive), select K numbers from the range (a number can be chosen multiple times) such that sum of those K numbers is even.

Calculate the number of all such permutations.

As this number can be large, print it modulo (1e9 +7).

Constraints
0 <= low <= high <= 10^9

K <= 10^6.

Input
First line contains two space separated integers denoting low and high respectively

Second line contains a single integer K.

Output
Print a single integer denoting the number of all such permutations

Time Limit
1

Examples
Example 1

Input

4 5

3

Output

4

Explanation

There are 4 valid permutations viz. {4, 4, 4}, {4, 5, 5}, {5, 4, 5} and {5, 5, 4} which sum up to an even number

Example 2

Input

1 10

2

Output

50

Explanation

There are 50 valid permutations viz. {1,1}, {1, 3},.. {1, 9} {2,2}, {2, 4},� {2, 10} . . . {10, 2}, {10, 4},� {10, 10}. These 50 permutations, each sum up to an even number.
*/


/*
Approach

An even sum can be generated as follows
1 if k is even then even sum can be generated by using any k even numbers from given range or any k odd numbers

2 If k is odd then even sum can be generated any k-1 odd numbers from range and 1 even number or any k even numbers from range

2.a If k is odd and number even numbers in range is zero then even sum cannot be generated hence return 0
*/

int evenOdd(vector<int> a,int k)
{
    int n=a.size();
    int res=0;      //result to be returned
    int numEven=0;  //number of even numbers in the range
    int numOdd=0;   //number of odd numbers in the range

    //calculating number of even and odd numbers
    for(int i=0;i<a.size();i++)
    {
        if(a[i]%2==0)
        {
            numEven++;
        }
        else
        {
            numOdd++;
        }
    }

    //if number of numbers to be used from range is even
    if(k%2==0)
    {
        //then either k even numbers should be picked or k odd numbers should be picked
        //Since repetition is allowed therefore formula becomes numEven^k + numOdd^k
        res=res+pow(numEven,k)+pow(numOdd,k);
        return res;
    }
    else
    {
        //if number of even numbers in range is zero and number of numbers to be picked from range is odd then return zero
        if(numEven==0)
        {
            return 0;
        }
        //else k-1 odd numbers should be picked with 1 even number or all k numbers should be even
        //if k-1 odd numbers need to be picked then 1 even number can be picked at k different places
        //for eg if k is 3 then odd,odd,even or odd,even,odd or even,odd,odd or even,even,even
        //this can be reduced to k*(numOdd^k-1)*numEven + numEven^k
        res=res+k*pow(numOdd,k-1)*numEven+pow(numEven,k);
        return res;
    }
}
int main()
{
    vector<int> a;
    for(int i=5;i<6;i++)
    {
        a.push_back(i);
    }
    cout<<evenOdd(a,3);

    return 0;
}