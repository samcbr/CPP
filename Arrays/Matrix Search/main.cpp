#include <iostream>

using namespace std;
int matrixSearch(int a[][100],int m,int n,int key)
{
    int i=0;
    int j=n-1;
    while(i<=m-1&&j>=0)
    {
        if(a[i][j]==key)
        {
            return 1;
        }
        else if(a[i][j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}
int main()
{
    int m;
    int n;
    cin>>m;
    cin>>n;
    int a[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;

    cout <<matrixSearch(a,m,n,key)<< endl;
    return 0;
}
