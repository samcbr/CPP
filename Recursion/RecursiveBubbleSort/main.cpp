#include <iostream>

using namespace std;
void recurBubbleSort(int *a,int n,int index=0)
{
    //In this function n is used as outer for loop and index is used for inner for loop
    if(n==0)
    {
        return;
    }
    if(index==n-1)
    {
        recurBubbleSort(a,n-1,0);   //reducing size of problem by 1 as the last element is in its position
                                    //index value is again passed as 0.
    }
    else
    {
        if(a[index]>a[index+1])
        {
            swap(a[index],a[index+1]);
        }
        recurBubbleSort(a,n,index+1);
    }

}
int main()
{
    int a[]={1,2,3,9,8,7,10,16};
    recurBubbleSort(a,8);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
