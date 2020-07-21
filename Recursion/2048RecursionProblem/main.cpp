#include <iostream>

using namespace std;
//Given a number convert it to spellings
//Input - 2048
//output - two zero four eight
void digitsToSpelling(int num)
{
    if(num==0)
        return;
    else
        digitsToSpelling(num/10);
    switch(num%10)
    {
        case 0: cout<<"zero"<<" ";
        break;
        case 1: cout<<"one"<<" ";
        break;
        case 2: cout<<"two"<<" ";
        break;
        case 3: cout<<"three"<<" ";
        break;
        case 4: cout<<"four"<<" ";
        break;
        case 5: cout<<"five"<<" ";
        break;
        case 6: cout<<"six"<<" ";
        break;
        case 7: cout<<"seven"<<" ";
        break;
        case 8: cout<<"eight"<<" ";
        break;
        case 9: cout<<"nine"<<" ";
        break;
    }
}
int main()
{
    digitsToSpelling(2048);
    return 0;
}
