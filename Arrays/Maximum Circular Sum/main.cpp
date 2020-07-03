#include <iostream>

using namespace std;
int maximumCircularSum(int *a,int n)
{
    int left=0;
    int right=0;
    int cur_max=0;
    int sum_max=0;
    for(int i=0;i<n;i++)
    {
        cur_max+=a[i];
        if(cur_max<0)
        {
            cur_max=0;
            left=i+1;
        }
        if(cur_max>sum_max)
        {
            right =i;
        }
        sum_max=max(cur_max,sum_max);
    }
    cur_max=0;
    left=right;
    for(int i=right;i<n;i++)
    {
        cur_max+=a[i];
        if(cur_max<0)
        {
            cur_max=0;
            left=i+1;
        }

        sum_max=max(cur_max,sum_max);
    }
    for(int i=0;i<left;i++)
    {
        cur_max+=a[i];
        if(cur_max<0)
        {
            cur_max=0;
        }
        sum_max=max(cur_max,sum_max);
    }


    return sum_max;
}
int main()
{

     int a[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Maximum circular sum is " << maximumCircularSum(a, n) << endl;
    return 0;
}
