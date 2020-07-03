
//This program takes input n number of strings and finds the largest string input till now
#include <iostream>
#include <cstring> //used for strcpy function
using namespace std;
void largestString()
{
    int largest_len=0;
    int cur_len=0;

    char largest[1000];
    char current[1000];

    int n;
    cin>>n;
    cin.get(); //To absorb null character

    for(int i=0;i<n;i++)
    {
        cin.getline(current,1000);
        cur_len=strlen(current);
        if(cur_len>largest_len)
        {
            strcpy(largest,current);
            largest_len=cur_len;
        }
    }
    cout<<largest<<endl;

}

int main()
{
    cout << "Hello world!" << endl;
    largestString();


    return 0;
}
