#include <iostream>

using namespace std;
int binarySearch(int *,int,int);
int main()
{
    int a[6]={1,2,3,50,89,109};
    int ind=binarySearch(a,6,109);
    cout<<ind<<endl;
    cout<<binarySearch(a,6,110);
    cout<<binarySearch(a,6,1);
    cout<<binarySearch(a,6,-1);
    return 0;
}
int binarySearch(int *a,int size1,int n)
{
    int i=0;
    int j=size1-1;
    int mid=(i+j)/2;
    while(i<=j)
    {
        if(a[mid]==n)
        {
            return mid;
        }
        else if(a[mid]>n)
        {
            j=mid-1;
            mid=(i+j)/2;
        }
        else{
            i=mid+1;
            mid=(i+j)/2;

        }
    }
    return -1;
}
