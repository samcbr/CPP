#include<iostream>
#include <climits>
using namespace std;
long long int maxElement(long long int a[],long long int n)
{
	long long int max=INT_MIN;
	for(long long int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
int main() {
	long long int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<maxElement(a,n);
	return 0;
}
