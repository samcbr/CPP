#include <iostream>

using namespace std;
int* bubbleSort(int *,int);
int main()
{
    int a[6]={66,2,78,22,200,11};
    int *b=bubbleSort(a,6);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
int* bubbleSort(int *a,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    return a;
}
