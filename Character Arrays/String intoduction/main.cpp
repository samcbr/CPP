#include <iostream>
#include<cstring>
using namespace std;
string differenceInAscii(string b)
{
    string s;
    int j=0;
    int diff;
    for(int i=0;i<b.length()-1;i++)
    {
        s+=b[i];
        diff=b[i]-b[i+1];
        s+=diff;
    }
    return s;
}
int main()
{
    cout << "Hello world" << endl;
    int a='a'+'A';
    cout<<a<<endl;
    string s="hello";
    int diff=s[0]-s[1];
    cout<<diff;
    return 0;
}
