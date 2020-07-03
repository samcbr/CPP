#include <iostream>
#include<algorithm>
/*Write a program that, given an array A[] of n numbers and another number x,
determines whether or not there exist two elements in S whose sum is exactly x.*/
using namespace std;
int pairSum(int *a,int n,int sum)
{
    sort(a,a+n);
    int mini=0;
    int maxi=n-1;
    int sumi;
    for(int i=0;i<n;i++)
    {
        sumi=a[mini]+a[maxi];

        if(maxi<=mini)
        {
            return -1;
        }
        if(sumi==sum)
        {
            return 1;
        }
        else if(sumi<sum)
        {
            mini++;
        }
        else
        {
            maxi--;
        }
    }
    return -1;
}
int main()
{
    int a[6]={1,2,3,4,5,6};
    cout<<pairSum(a,6,11);
    return 0;
}
