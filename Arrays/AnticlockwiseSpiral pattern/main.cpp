#include <iostream>

using namespace std;

int main()
{
    int m;
    int n;
    cin>>m;
    cin>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int row_top=0;
    int row_bottom=m-1;
    int col_left=0;
    int col_right=n-1;
    while(row_top<=row_bottom&&col_left<=col_right)
    {
        //first column
        for(int i=row_top;i<=row_bottom;i++)
        {
            cout<<a[i][col_left]<<", ";
        }
        //first row
        for(int i=col_left+1;i<=col_right;i++)
        {
            cout<<a[row_bottom][i]<<", ";
        }
        //second column
        if(col_left<col_right)
        {
            for(int i=row_bottom-1;i>=row_top;i--)
            {
                cout<<a[i][col_right]<<", ";
            }
        }

        //second row
        if(row_top<row_bottom)
        {
            for(int i=col_right-1;i>col_left;i--)
            {
                cout<<a[row_top][i]<<", ";
            }
        }

        row_top++;
        row_bottom--;
        col_left++;
        col_right--;
    }
    cout<<"END"<<endl;
    return 0;
}
