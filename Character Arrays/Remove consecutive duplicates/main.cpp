#include <iostream>
#include<cstring>
using namespace std;
char * removeConsecutiveDuplicates(char a[])
{
    int j=1;
    int i=0;
    for( j=1;j<strlen(a);j++)
    {
        if(a[i]!=a[j])
        {
            i++;
            a[i]=a[j];
        }

    }
    a[++i]='\0';
    return a;
}
int main()
{
    cout << "Hello world!" << endl;
    char a[]="cooodiiim";
    char *b=removeConsecutiveDuplicates(a);
    cout<<b;
    return 0;
}
