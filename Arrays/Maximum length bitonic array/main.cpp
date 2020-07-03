#include <iostream>

using namespace std;
long long int maxBitonicArray(long long int *a,long long int n)
{
    long long int left,right,mid;
    long long int cur=1;
    long long int max_len=0;
    //increasing or decreasing array
    /*long long int flag1,flag2=0;
    for(long long int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
            flag1=1;

        if(a[i]>a[i+1])
            flag2=1;

        cur++;

    }
    if(flag1!=flag2)
    {
        return cur;
    }*/


    cur=1;
    for(long long int i=0;i<=n-2;i++)
    {
        left=i;
        mid=i+1;
        right=i+2;
        if(a[left]<=a[mid]&&a[mid]>=a[right])
        {
            cur=3;
            while(left>0)
            {
                if(a[left]>=a[left-1])
                {
                    cur++;
                    left--;
                }
                else
                    break;
            }
            while(right<n)
            {

                if(a[right]>=a[right+1])
                {
                    cur++;
                    right++;
                }
                else
                    break;
            }
            max_len=max(cur,max_len);
        }
    }
    return max_len;
}
int main()
{
    long long int t;
    cin>>t;
    while(t>0)
    {
        long long int n;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<maxBitonicArray(a,n)<<endl;
        t--;
    }

    return 0;
}
