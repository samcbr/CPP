#include <iostream>
#include<algorithm>
using namespace std;
void tripletSum(int *a,int n,int sum)
{
    sort(a,a+n);
    int left=0;
    int right=n-1;
    int mid;
    int sumi;
    sumi=a[left]+a[right];
    while((right-left)>1)
    {
        while((right-left)>1)
        {
        sumi=a[left]+a[right];
        if(sumi>=sum)
        {
            right--;
        }
        if(sumi<sum)
        {
            mid=right-1;
            while(mid>left)
            {
                if((sumi+a[mid])==sum)
                {
                    cout<<a[left]<<", "<<a[mid]<<" and "<<a[right]<<endl;

                }
                else if((sumi+a[mid])<sum)
                {
                    break;
                }
                mid--;
            }
            right--;
        }
        }
        left++;
        right=n-1;
    }
}
int main()
{

    int n;
    cin>>n;
    int a[n];
    int sum;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>sum;
    tripletSum(a,n,sum);
    return 0;
}
