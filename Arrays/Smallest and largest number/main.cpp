#include <iostream>

using namespace std;

int main()
{
    int a[5]={1};
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    int small=INT_MAX;
    int flag;
    for(int i=0;i<5;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
            flag=i;
        }
    }
    cout<<small<<"element at"<<flag;
    return 0;
}
