#include <iostream>

using namespace std;
int* insertionSort(int* , int);
int main()
{
    int a[6]={40,30,59,10,3,1};
    insertionSort(a,6);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
int* insertionSort(int *a,int n)
{
    for(int i=1;i<=n-1;i++)
    {
        int flag=a[i];
        int j=i-1;
        while(j>=0)
        {
            if(flag<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            else{
                break;
            }
        }
        a[j+1]=flag;
    }
    return a;
}
