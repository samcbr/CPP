#include <iostream>

using namespace std;
int missingNumber(int a[],int n)
{

}
int main()
{
    int n;
    int m;
    cin>>n;
    while(n>0)
    {
        cin>>m;
        int a[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        cout<<missingNumber(a,m);
    }
    return 0;
}
