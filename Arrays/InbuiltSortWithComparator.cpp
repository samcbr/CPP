#include <iostream>
#include <algorithm> //header file required for sort function
using namespace std;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int a[6]={40,20,50,70,35,90};
    sort(a,a+6); //inbuilt sort function takes two parameters start address and end address. End address is not included
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
    sort(a,a+6,compare);    //Sort function takes in a 3rd parameter which is basically a comparator function
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
