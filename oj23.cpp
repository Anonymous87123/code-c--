#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double height, climb_perday;
    while(cin >> height >> climb_perday)
    {
        int day = 1;
        double current_height = 0;
        while(current_height < height)
        {
            double temp = current_height;
            current_height += climb_perday*(1.0/(pow(3,day-1)));
            if(current_height >= height){cout<<day<<endl;break;}
            current_height -= 1;
            if(current_height<=temp){cout<<"Never"<<endl;break;}
            day++;
        }
    }
}