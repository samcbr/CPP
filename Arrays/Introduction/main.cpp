#include <iostream>

using namespace std;
void wavePrint(int a[3][4],int n,int m)
{
    int i=0;
    int k=0;
    for(int j=0;j<m;j++)
    {
        if(i%2==0)
        {
            k=0;
            while(k<n)
            {
                cout<<a[k][j];
                k++;
            }
            i++;
        }
        else
        {
           k=n-1;
           while(k>=0)
           {
               cout<<a[k][j];
               k--;
           }
           i++;
        }
        cout<<endl;
    }

}
int main()
{
    int a[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }
    wavePrint(a,3,4);

    cout << "Hello world!" << endl;
    return 0;
}
