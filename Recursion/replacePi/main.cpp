#include <iostream>

using namespace std;
//Input-"xpighpilmpipi"
//Output - "x3.14gh3.14lm3.143.14"


//Approach
//index is used to locate '\0'
//n is used to track the number of elements in char array
//Whenever 'p' is found at the a[0] and 'i' is found at a[1] then move all elements of array by 2 starting from last element to make space for 3.14
//Replace pi by 3.14 and move a to a+4 and start searching again
void replacePi(char a[],int n,int index)
{
    if(n<2)
    {
        cout<<"exiting"<<endl;      //Base case
        return;
    }

    if(index==0)
    {
        a[0]='3';
        a[1]='.';
        a[2]='1';
        a[3]='4';
        replacePi(a+4,n-2,n-2);
    }

    else
    {
        if(index!=n)    //if index is not equal to n implies that pi was found so continue moving elements by 2 till index becomes index of 'p' ie 0
        {
            a[index+2]=a[index];
            replacePi(a,n,index-1);
        }
        else if(a[0]=='p'&&a[1]=='i')   //If pi is found than make space for replacing pi by 3.14 by shifting all elements by 2 starting from last element till p
        {

            a[index+2]=a[index];
            replacePi(a,n,index-1);
        }
        else
            replacePi(a+1,n-1,index-1);   //If pi was not found then move to next element

    }
}
int main()
{
    char a[100]="xpighpilmpipi";
    replacePi(&a[0],13,13);
    cout<<a;
    return 0;
}
