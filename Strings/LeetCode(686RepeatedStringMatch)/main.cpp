#include <iostream>

using namespace std;
/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
/*
Approach
1. We will append A to A till length of A just becomes greater than B.
2. After this we will check if pattern B exists in A and return count.
3. If not then we will append A one more time to A and again check if pattern B is present in A and present.
Explanation for step 3
There are 3 types of cases which can be formed
a. A- abcd (4)
   B- cdabcd (6)
   A1- abcdabcd (8)

b. A- abcd (4)
   B- cdabcdab (8)
   A1- abcdabcdabcd (12)

c. A- abcd (4)
   B- abcdab (6)
   A1- abcdabcd (8)
*/
//Pattern matching logic
int findPattern(string str,string pat)
{
    int n=str.length();
    int m=pat.length();

    int i=0;
    int j=1;

    //First we will pre process the pattern and create lps array for the same
    int lps[m];//lps array will have same size as pattern length
    lps[i]=0;
    while(j<m)
    {
        if(pat[i]==pat[j])
        {
            i++;
            lps[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=lps[i-1];     // Dry run this pattern to understand the reason for this step "ABAAABAAB"
                //lps array for above pattern should be {0,0,1,1,1,2,3,4,2}
            }
            else //i=0
            {
                lps[j]=i;
                j++;
            }
        }
    }

    //Now we will find the pattern in string and print index of the pattern in string
    j=0;    //used for traversing the string
    i=0;    //used for traversing the string

    //In this while loop we never backtrack i instead we only backtrack j when there is a mismatch
    while(i<n)
    {
        if(j<m)
        {
            if(pat[j]==str[i])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            return 1;
            j=lps[j-1];     //This is specifically done to handle overlapping pattern in string
        }
    }
    if(j==m)
    {
        return 1;
    }
    return -1;
}
//Logic for question
int repeatedStringMatch(string A, string B)
{
    if(A.length()==0&&B.length()==0)
        return 0;
    if(A.length()==0||B.length()==0)
        return -1;


    string A1=A;
    int count=1;
    //while length of A becomes just greater than B
    while(A1.length()<B.length())
    {
        A1+=A;
        count++;

    }
    cout<<A1<<endl;
    int found=findPattern(A1,B);
    if(found==1)
        return count;
    //Append A to A1 one more time
    else
    {
        A1+=A;
        cout<<A1<<endl;
        found=findPattern(A1,B);
        if(found==1)
        {
            count++;
            return count++;
        }
    }
    return -1;
}
int main()
{
    string A="abcd";
    string B="cdabcdab";
    cout<<repeatedStringMatch(A,B);
    return 0;
}
