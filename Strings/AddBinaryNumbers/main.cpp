#include <iostream>

using namespace std;
/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
problem link : https://leetcode.com/problems/add-binary/
*/
string addBinary(string a,string b)     //Made by someone else
{

        const int aLength = a.length();
        const int bLength = b.length();
        const int resultLength = max(aLength, bLength) + 1;

        char* result = new char[resultLength + 1];
        result[resultLength] = '\0';

        int resultIndex = resultLength - 1;
        int carry = 0;

        for(int i = aLength-1, j = bLength-1; i>=0 || j >=0; i--, j--, resultIndex--)
        {
            const int aVal = (i >= 0 ? a[i] : 48) - 48;
            const int bVal = (j >= 0 ? b[j] : 48) - 48;
            const int sum = aVal + bVal + carry;
            result[resultIndex] = (sum % 2) + 48;
            carry = sum / 2;
        }

        if (carry > 0)
            result[resultIndex] = carry + 48;
        else
            result++;   //if no carry in final bit then it should return array from index 1 else index 0

        return result;

}
string addBinary2(string a,string b)    //your solution
    {   //avoid using string class to reduce time and space
        int i=a.length()-1;
        int j=b.length()-1;
        int cur1;
        int cur2;
        string res;
        int rem=0;
        while(i>=0&&j>=0)
        {
            cur1=a[i]-48;
            cur2=b[j]-48;
            if((rem+cur1+cur2)>2)
            {
                rem=1;
                res="1"+res;
            }
            else if((rem+cur1+cur2)>1)
            {
                rem=1;
                res="0"+res;
            }
            else if((rem+cur1+cur2)==1)
            {
                rem=0;
                res="1"+res;
            }
            else
            {
                rem=0;
                res="0"+res;
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            cur1=a[i]-48;
            if((rem+cur1)>1)
                {
                    rem=1;
                    res="0"+res;
                }
            else if((rem+cur1)==1)
                {
                    rem=0;
                    res="1"+res;
                }
            else
                {
                    rem=0;
                    res="0"+res;
                }
                i--;
        }
        while(j>=0)
        {
            cur1=b[j]-48;
            if((rem+cur1)>1)
                {
                    rem=1;
                    res="0"+res;
                }
            else if((rem+cur1)==1)
                {
                    rem=0;
                    res="1"+res;
                }
            else
                {
                    rem=0;
                    res="0"+res;
                }
                j--;
        }
            if(rem>0)
             {
                 res="1"+res;
             }
             return res;
        }
int main()
{
    cout << addBinary2("100","110010")<< endl;
    return 0;
}
