#include <iostream>
#include<algorithm>
using namespace std;
//Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
//Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

//Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
//Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}


//Approach
//Step 1 Sort the array
//Step 2 Create a 2d array and store each unique element along with its frequency row wise
//Step 3 Sort the 2d array
void sortElementsByFrequency(int a[],int n)
{
    int b[n][2];    //This array is used to store the count of unique element mapped with the element
                    //In worst case all elements will be unique hence size is taken as n

    int unique;
    int count=1;
    int k=0;
    sort(a,a+n);
    unique=a[0];
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
        }
        else
        {
            b[k][0]=unique;
            b[k][1]=count;
            k++;
            count=1;
            unique=a[i+1];
        }
    }
    b[k][0]=unique;
    b[k][1]=count;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }


    int max;
    for(int i=0;i<=k;i++)
    {
        max=i;
        for(int j=i+1;j<=k;j++)
        {
            if(b[max][1]<b[j][1])
            {
                max=j;

            }
        }
        if(b[max][1]!=b[i][1])
        {
            swap(b[max][0],b[i][0]);
            swap(b[max][1],b[i][1]);
        }
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }

}
int main()
{
    int a[]={5,2,2,8,5,6,8,8};
    sortElementsByFrequency(a,8);
    return 0;
}
