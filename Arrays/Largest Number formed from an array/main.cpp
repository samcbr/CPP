
/*

Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line of each test case contains the size of the array, and the second line has the elements of the array.

Output:
In each separate line print the largest number formed by arranging the elements of the array in the form of a string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 102
0 ≤ A[i] ≤ 103

Example:
Input:
2
5
3 30 34 5 9
4
54 546 548 60

Output:
9534330
6054854654

*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void largestNumberFromArray(int a,int n)
{
    int el1=a;
    int el2=n;
    int len1;
    int len2;
    int cur1[4];
    int cur2[4];
    int i=0;
    int j=0;
    int max=INT_MIN;
    while(a>0)
    {
        cur1[i]=a%10;
        a=a/10;
        i++;
    }
    while(n>0)
    {
        cur2[j]=n%10;
        n=n/10;
        j++;
    }
    i--;
    j--;
    len1=i;
    len2=j;
    while(i>=0&&j>=0)
    {
        if(cur1[i]>cur2[j])
        {
            max=el1;
            cout<<cur1[j]<<endl;
            break;
        }
        else if(cur2[j]>cur1[i])
        {
            cout<<cur2[j]<<" "<<cur1[i]<<endl;
            max=el2;
            break;
        }
        i--;
        j--;
    }
    if(i>=0&&j<0)
    {
        if(cur1[i]>cur2[len2])
        {
            max=el1;
        }
        else
            max=el2;
    }
    if(j>=0&&i<0)
    {

        if(cur2[j]>cur1[len1])
        {
            max=el2;
        }
        else
            max=el1;

    }

    cout<<max;
}
string largestNumberFromArray2(int *a,int n)
{
    string s;
    int max=-1;
    int number1;
    int number2;
    int num1[4];
    int num2[4];
    int j=0;
    int k=0;
    int len1;
    int len2;
    for(int p=0;p<n;p++)
    {
       for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
                continue;

            if(max==-1)
            {
                max=i;
                continue;
            }

            number1=a[max];
            number2=a[i];
            while(number1>0)
            {
                num1[j]=number1%10;
                j++;
                number1=number1/10;
            }
            while(number2>0)
            {
                num2[k]=number2%10;
                k++;
                number2=number2/10;
            }
            j--;
            k--;

            len1=j;
            len2=k;
            while(j>=0&&k>=0)
            {
                if(num1[j]>num2[k])
                {
                    break;
                }
                if(num2[k]>num1[j])
                {
                    max=i;
                    break;
                }
                j--;
                k--;
            }
            if(j>=0&&k<0)
            {
                if(num1[j]<num2[len2])
                    max=i;
            }

            if(k>=0&&j<0)
            {
                if(num2[k]>num1[len1])
                    max=i;
            }
        }

        //s=s+;
        cout<<a[max]<<" ";
        a[max]=-1;
        j=0;
        k=0;
        max=-1;


    }
    return s;
}


int main()
{

    //cout<<to_string(4);
    int a[]={9,97,98,96};
    cout<<largestNumberFromArray2(a,4);

    return 0;
}
