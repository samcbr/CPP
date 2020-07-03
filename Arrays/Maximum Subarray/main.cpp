#include <iostream>

using namespace std;

int main()
{
    int a[9]={-4,1,3,-2,6,2,-1,-4,-7};
    int n=9;
    int k;
    int sum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(sum>maxSum)
            {
                maxSum=sum;
            }
        }

    }
    cout<<maxSum;
    return 0;
}
