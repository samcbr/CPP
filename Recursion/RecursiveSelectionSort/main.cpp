#include <iostream>

using namespace std;
void recursiveSelectionSort(int a[],int n,int index,int min_index)
{
    if(n==1)
    {
        return;
    }
    if(index==n)
    {
        if(a[0]>a[min_index])
        {
            swap(a[0],a[min_index]);
        }
        recursiveSelectionSort(a+1,n-1,0,0);
    }
    else
    {
        if(a[index]<a[min_index])
        {
            min_index=index;
        }
        recursiveSelectionSort(a,n,index+1,min_index);
    }
}
int main()
{
    int a[]={5,4,3,2,1,8,9,10};
    recursiveSelectionSort(a,8,0,0);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
