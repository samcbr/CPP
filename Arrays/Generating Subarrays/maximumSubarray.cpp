#include <iostream>
using namespace std;
int main()
{
    int a[6]={1,2,3,4,5,6};
    int n=6;
    int k;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
