#include <iostream>

using namespace std;
int * selectionSort(int *,int);
int main()
{
    cout << "Hello world!" << endl;
    int a[5]={1,2,7,3,5};

    int *b=selectionSort(a,5);
    for(int i=0;i<5;i++)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}
int* selectionSort(int a[],int n)
{   int mini;
    int flag;
    int j;
    int temp;
    for(int i=0;i<n;i++)
    {
        flag=i;
        mini=INT_MAX;
        for(j=i+1;j<n;j++)
        {
            if(mini>a[j])
            {
                mini=a[j];
                flag=j;
            }
        }
        if(a[i]>a[flag])
        {
            temp=a[flag];
            a[flag]=a[i];
            a[i]=temp;
        }
    }
    return a;
}
