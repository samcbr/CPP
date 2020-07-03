#include <iostream>
#include<cstring>
using namespace std;
bool isPalindrome(char a[])
{
    int i=0;
    int j=strlen(a)-1;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{

    char b[]={'h','e','l','l','o','o'};   //Does not add null char by default

    char a[]="helloo"; //adds null character by default


    cout<<strlen(a);    //returns 6 (It does not include null character while calculating length)
    //Use strlen in for loops for character arrays and not sizeof
    cout<<sizeof(a);    //return 7 (It includes null character while calculating length)

    char c[]="naman";

    cout<<isPalindrome(c);

    cout << "Hello world!" << endl;
    return 0;
}
