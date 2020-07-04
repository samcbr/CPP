#include <iostream>

using namespace std;

int main()
{
    int a[][1000]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18} };
    int row_top=0;
    int row_bottom=2;
    int col_left=0;
    int col_right=5;
    while(row_top<=row_bottom&&col_left<=col_right)
    {
        //first column
        for(int i=row_top;i<=row_bottom;i++)
        {
            cout<<a[i][col_left]<<" ";
        }
        //first row
        for(int i=col_left+1;i<=col_right;i++)
        {
            cout<<a[row_bottom][i]<<" ";
        }
        //second column
        if(col_left<col_right)
        {
            for(int i=row_bottom-1;i>=row_top;i--)
            {
                cout<<a[i][col_right]<<" ";
            }
        }

        //second row
        if(row_top<row_bottom)
        {
            for(int i=col_right-1;i>col_left;i--)
            {
                cout<<a[row_top][i]<<" ";
            }
        }

        row_top++;
        row_bottom--;
        col_left++;
        col_right--;
    }
    return 0;
}
