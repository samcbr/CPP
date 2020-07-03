#include <iostream>

using namespace std;
void rotateImage(int a[][3],int m,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[j][i];
        }
        cout<<endl;
    }
}
int main()
{
    int a[][3]={ {1,2,3},{4,5,6},{7,8,9} };
    rotateImage(a,3,3);
    cout << "Hello world!" << endl;
    return 0;
}
