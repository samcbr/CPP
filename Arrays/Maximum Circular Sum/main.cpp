#include <iostream>

using namespace std;
int maximumCircularSum(int *a,int n)
{
    int i=0;
    int j=0;
    int cur=0;
    int max=0;
    while(j<n)
    {
        cur+=a[j];
        if(cur<0)
        {
            i=j+1;
            j++;
            cur=0;
        }
        else{
            j++;
            if(max<cur)
            {
                max=cur;
            }
        }
    }
    j=0;
    while(j<i)
    {
        cur+=a[j];
        if(cur<0)
        {
            break;
        }
        else{
            j++;
            if(max<cur)
            {
                max=cur;
            }
        }
    }
    return max;
}
int main()
{

    int n;
    cin>>n;
    int size1;

    while(n>0)
    {
        cin>>size1;
        int a[size1];
        for(int i=0;i<size1;i++)
        {
            cin>>a[i];
        }
        cout<<maximumCircularSum(a,size1)<<endl;
        n--;
    }
    return 0;
}
