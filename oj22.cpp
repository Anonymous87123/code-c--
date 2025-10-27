#include <iostream>
using namespace std;
bool is_leap_year(int year)
{
    if (year % 4 == 0 && (year % 100!= 0 || year % 400 == 0)){return true;}
    else{return false;}
}
int main() 
{
    int n;
    while (cin>>n)
    {
        int i=1;
        while(n>=365)
        {
            if(is_leap_year(2024+i)==true&&n>=366){n-=366;i++;}
            else if(is_leap_year(2024+i)==false){n-=365;i++;}
        }
        while(n>=28)
        {
            if(is_leap_year(2024+i)==true)
        }

    }
    }
    
}

