#include <iostream>
#include<bits/stdc++.h>
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
{   int min;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;

        }
        swap(a[i],a[min]);
    }
    return a;
}
