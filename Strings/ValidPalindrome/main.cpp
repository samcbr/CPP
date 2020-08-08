#include <iostream>

using namespace std;
/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.

Problem url - https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/
*/

/*
Approach

1. Use two pointers left and right
2. Compare only when left and right point at either a number or an alphabet
3. if left and right point to any other characters then increment or decrement them.
*/
bool isPalindrome(string s) {
    int left,right;
    left=0;         //left pointer starting from zero
    right=s.length()-1; //right pointer starting from length -1
        while(left<=right)
        {

            if((s[left]>=65&&s[left]<=90)||(s[left]>=97&&s[left]<=122)||(s[left]>=48&&s[left]<=57)) //if s[left] is an alphabet or number
            {
                if((s[right]>=65&&s[right]<=90)||(s[right]>=97&&s[right]<=122)||(s[right]>=48&&s[right]<=57)) //if s[right] is an alphabet or number
                {

                    if(tolower(s[left])!=tolower(s[right])) //change both to lower case since input is uppercase and lower case
                        return false;
                    else
                    {
                        left++;
                        right--;
                    }
                }
                else    //if s[right] is not number or alphabet then right--
                {
                    right--;
                }
            }
            else    //if s[left] is not number or alphabet then left++
            {
                left++;
            }
        }
        return true;
}
int main()
{
    string s="0P";
    cout <<isPalindrome(s)<< endl;
    return 0;
}
