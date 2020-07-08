#include <iostream>

using namespace std;
void rotateImage(int a[][1000],int n)
{
    int i=0;
    int j=n-1;
    int col;
    int temp;
    int row;
    while(j>=0)
    {
        col=j-1;
        row=i+1;
        while(row<=n-1)
        {
            temp=a[row][j];
            a[row][j]=a[i][col];
            a[i][col]=temp;
            row++;
            col--;
        }
        j--;
        i++;
    }
    int k=n-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(k>=j)
            {
                swap(a[i][j],a[i][k]);
            }
            k--;
        }
        k=n-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n][1000];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    rotateImage(a,n);
    return 0;
}
