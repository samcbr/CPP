#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Leetcode problem 121
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/*
Approach

In its naive approach we will find all pairs for each day and give out the result
In this approach j depends on i such that j starts from i+1
Therefore we can use stack and have to start from the end
Instead of stack we are using sellDay variable since only one value needs to be in stack

*/
int maxProfit(vector<int>& prices)
{
        int sellDay=prices.size()-1;    //sellDay set as last index
        int profit=0;
        int maxProfit=0;
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(prices[i]>prices[sellDay])   //if current price is greater than sellDay then set sellDay as current price and continue
            {
                sellDay=i;
                continue;
            }
            else        //else find profit and check if profit is greater then maxProfit
            {
                profit=prices[sellDay]-prices[i];
                if(profit>maxProfit)
                {
                    maxProfit=profit;
                }
            }
        }
        return maxProfit;
    }
int main()
{
    int a[]={7,1,5,3,6,4};
    vector<int> v(a,a+6);
    cout<<maxProfit(v);
    return 0;
}
