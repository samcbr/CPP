#include <iostream>

using namespace std;
bool sortedCheck(int a[],int n)
{
    if(n==0)
    {
        return true;
    }
    if(a[n]>=a[n-1])
    {
        return sortedCheck(a,n-1);
    }
    else{
        return false;
    }
}
int main()
{
    int a[]={1,2,3,4,5,6};
    cout<<sortedCheck(a,5);

    return 0;
}
