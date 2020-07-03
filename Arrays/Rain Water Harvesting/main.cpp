#include <iostream>

using namespace std;
long long int rainWaterHarvesting(long long int *a,long long int n)
{
    long long int flag=-1;
    long long int sum=0;
    long long int i=0;
    if(a[i]>a[i+1])
    {
        flag=i;
    }
    for(i=1;i<n-1;i++)
    {
        if(a[i]>a[i+1]&&a[i]>a[i-1]&&flag!=-1)
        {
            if(a[flag]<=a[i])
            {
                for(long long int j=flag+1;j<=i-1;j++)
                {
                    sum=sum+a[flag]-a[j];
                }
            }
            else
            {
                for(long long int j=flag+1;j<=i-1;j++)
                {
                    sum=sum+a[i]-a[j];
                }
            }
            flag=i;
        }

        if(a[i]>a[i+1]&&a[i]>a[i-1]&&flag==-1)
        {
            flag=i;
        }
    }
    if(a[i]>a[i-1])
    {
        if(a[flag]<=a[i])
            {
                for(long long int j=flag+1;j<=i-1;j++)
                {
                    sum=sum+a[flag]-a[j];
                }
            }
            else
            {
                for(long long int j=flag+1;j<=i-1;j++)
                {
                    sum=sum+a[i]-a[j];
                }
            }
    }
    return sum;
}
long long int rainWaterHarvestingM(int *a,int n)
{
    int i=0;
    int flagl=0;
    int flagr=n-1;
}
int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<rainWaterHarvesting(a,n);
    return 0;
}
