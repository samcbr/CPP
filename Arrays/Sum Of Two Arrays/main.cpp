#include <iostream>

using namespace std;
int* sumOfTwoArrays(int a[],int b[],int sizea,int sizeb)
{
    int carry=0;

    int i=sizea-1;
    int j=sizeb-1;
    int cur=0;
    int *sum=new int[i+j];
    if(i>j)
    {
        cout<<"i>j"<<endl;
        while(j>=0)
        {
            cur=carry+a[i]+b[j];
            if(cur>9)
            {
                sum[i]=cur%10;
                cout<<sum[i]<<i<<endl;
                carry=1;
            }
            else
            {
                sum[i]=cur;
                cout<<sum[i]<<i<<endl;
                carry=0;
            }
            j--;
            i--;
        }
        while(i>=0)
        {
            cur=carry+a[i];
            if(cur>9)
            {
                sum[i]=cur%10;
                cout<<sum[i]<<i<<endl;
                carry=1;
            }
            else
            {
                sum[i]=cur;
                cout<<sum[i]<<i<<endl;
                carry=0;
            }
            i--;
        }
    }

    else
        {
            while(i>=0)
            {
                cur=carry+a[i]+b[j];
                if(cur>9)
                    {
                        sum[j+1]=cur%10;
                        carry=1;
                    }
                else
                {
                    sum[j]=cur;
                    carry=0;
                }
                i--;
                j--;
            }
            while(j>=0)
            {
                cur=carry + b[j];
                if(cur>9)
                {
                    sum[j+1]=cur%10;
                    carry=1;
                }
                else
                {
                    sum[j+1]=cur;
                    carry=0;
                }
                j--;
            }
            if(carry==0)
            {
                for(int k=0;k<=sizeb-1;k++)
                {
                    sum[k]=sum[k+1];
                }
            }
            else{
                sum[0]=carry;

            }
        }

    return sum;
}
void sumOfTwoArrays2(int a[],int b[],int sizea,int sizeb)
{
    int i=sizea-1;
    int j=sizeb-1;
    int cur=0;
    int carry=0;
    int len;
    int k;
    int *sum=new int[i+j];
    if(i>j)
    {
        k=i;
        len=i;
    }
    else{
        k=j;
        len=j;
    }
    while(i>=0&&j>=0)
    {
        cur=a[i]+b[j]+carry;
        if(cur>9)
        {
            carry=1;
            sum[k]=cur%10;
            cur=0;
        }
        else{
            sum[k]=cur;
            cur=0;
            carry=0;
        }
        k--;
        i--;
        j--;
    }
    while(i>=0)
    {
        cur=a[i]+carry;
        if(cur>9)
        {
            carry=1;
            sum[k]=cur%10;
            cur=0;
        }
        else{
            sum[k]=cur;
            cur=0;
            carry=0;
        }
        k--;
        i--;
    }
    while(j>=0)
    {
        cur=b[j]+carry;
        if(cur>9)
        {
            carry=1;
            sum[k]=cur%10;
            cur=0;
        }
        else{
            sum[k]=cur;
            cur=0;
            carry=0;
        }
        k--;
        j--;
    }
    if(carry!=0)
    {
        cout<<carry<<", ";
    }

    for(int i=0;i<=len;i++)
    {
        cout<<sum[i]<<", ";
    }
    cout<<"END";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    sumOfTwoArrays2(a,b,n,m);

    return 0;
}
