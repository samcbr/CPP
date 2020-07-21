#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void mergeSort(int *a,int n,int *b,int m)   //This function takes two sorted arrays as input always
{
    int aux[n+m];
    int i=0;
    int j=0;
    int k=0;
    while(i<n&&j<m)
    {
        if(a[i]>b[j])
        {
            aux[k]=b[j];
            j++;
        }
        else
        {
            aux[k]=a[i];
            i++;
        }
        k++;
    }
    while(i<n)
    {
        aux[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        aux[k]=b[j];
        j++;
        k++;
    }
    k=0;
    for(i=0;i<n;i++)
    {
        a[i]=aux[k];
        k++;
    }
    for(i=0;i<m;i++)
    {
        b[i]=aux[k];
        k++;
    }
}
void merge(int *a,int n)
{
    int mid;
    if(n==1)        //Base case when size of array = 1 then it is already sorted
    {
        return;
    }
    else
    {
        mid=n/2;
        merge(a,mid);
        merge(a+mid,n-mid);
        mergeSort(a,mid,a+mid,n-mid);
    }
}
int main()
{
    int a[]={6,5,4,3,2,1};
    merge(a,6);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
