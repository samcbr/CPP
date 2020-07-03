#include <iostream>

using namespace std;
void stringCompression(char a[])
{
    int i=0;
    int j=1;
    int count1=1;
    while(a[j]!='\0')
    {
        if(a[i]==a[j])
        {
            count1++;
            j++;
        }
        else
        {
            cout<<a[i]<<count1;
            count1=1;
            i=j;
            j++;
        }
    }
    cout<<a[i]<<count1;

}
int main()
{

    char a[]="aaabbccds";
    stringCompression(a);
    cout<<b;
    return 0;
}
