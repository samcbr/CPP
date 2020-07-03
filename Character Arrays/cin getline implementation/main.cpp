#include <iostream>

using namespace std;
void getLine(char a[],int m,char delim='\n')
{
    int i=0;
    char ch=cin.get();
    while(ch!=delim)
    {
        if(i==m-1)
        {
            break;
        }
        a[i]=ch;
        i++;
        ch=cin.get();
    }
    a[i]='\0';
    cout<<a;
}
int main()
{
    cout << "Hello world!" << endl;
    char a[10];
    getLine(a,10);
    return 0;
}
