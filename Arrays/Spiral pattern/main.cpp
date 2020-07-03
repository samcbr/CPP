#include <iostream>

using namespace std;
void spiralPattern(int a[][100],int m,int n)
{
    int flag1=0;
    int flag2=n-1;
    int flag3=m-1;
    int flag4=0;

    while(flag1<=flag3&&flag4<=flag2)
    {
        for(int i=flag1;i<=flag2;i++)
        {
            cout<<a[flag1][i];
        }
        cout<<endl;
        for(int i=flag1+1;i<=flag3;i++)
        {
            cout<<a[i][flag2];
        }
        cout<<endl;
        if(flag1<flag3)
        {
            for(int i=flag2-1;i>=flag4;i--)
            {
                cout<<a[flag3][i];
            }
        }
        cout<<endl;
        if(flag4<flag2)
        for(int i=flag3-1;i>=flag1+1;i--)
        {
            cout<<a[i][flag4];
        }
        cout<<endl;
        flag1++;
        flag3--;
        flag2--;
        flag4++;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    int a[5][100]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30}};
    spiralPattern(a,5,6);


    return 0;
}
