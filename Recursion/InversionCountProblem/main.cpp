#include <iostream>

using namespace std;
/*Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2)
*/

//Naive Approach
//index is used to traverse the array
//n is used to reduce the size of array by 1
//total is used to store size of original array
void naiveInversionCountProblem(int a[],int n,int index,int total)
{
    if(n==1)        //Base case(acts like outer for loop exit condition)
        return;
    if(index==total)    //Sub base case (acting like inner for loop exit condition)
       {
            cout<<endl;
            inversionCountProblem(a+1,n-1,0,total);

       }
    else
    {
        if(a[0]>a[index])
            cout<<a[0]<<" "<<index<<" ";
        inversionCountProblem(a,n,index+1,total);
    }

}
//Approach using merge Sort

int main()
{
    int a[]={6,5,4,3,2,1};
    inversionCountProblem(a,6,0,6);
    return 0;
}
