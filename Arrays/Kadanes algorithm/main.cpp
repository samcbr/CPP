#include <iostream>
#include <climits>
using namespace std;
int kadane(int a[],int m)
{
    int cur_sum=0;
    int max_sum=INT_MIN;

    int i=0;
    int j=0;
    while(j<m)
    {
        cur_sum+=a[j];
        if(cur_sum>max_sum)
        {
            max_sum=cur_sum;
        }
        if(cur_sum<0)
        {
            i=j+1;
            j++;
            cur_sum=0;
            continue;
        }

        j++;
    }


    return max_sum;
}
int main() {
	//code
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
	    cout<<kadane(a,m)<<endl;
	    n--;
	}
	return 0;
}
