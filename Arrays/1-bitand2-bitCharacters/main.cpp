#include <iostream>

using namespace std;
/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input:
bits = [1, 0, 0]
Output: True
Explanation:
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input:
bits = [1, 1, 1, 0]
Output: False
Explanation:
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

PROBLEM LINK : https://leetcode.com/problems/1-bit-and-2-bit-characters/
*/

/*
Approach

Start traversing the array if current element is one then increment i by 2 else do nothing
In this manner if you reach exactly second last element then last element has to be zero i.e one bit char return true
else if you reach last element then last element must have been a two bit char return false

*/
bool isOneBitCharacter(vector<int>& bits)
{
    int i;
    for(i=0;i<bits.size()-1;i++)
    {
        if(bits[i]==1)
        {
            i++;
            continue;
        }

    }
    if(i==bits.size()-1)
        return true;

    return false;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
