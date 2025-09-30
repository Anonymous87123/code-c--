#include <iostream>
using namespace std;
int main()
{
    int m1;
    int array[5];
    while(cin>>m1)
    {
        array[0]=m1/10000;
        int m2 = m1%10000;
        array[1]=m2/1000;
        int m3 = m2%1000;
        array[2]=m3/100;
        int m4 = m3%100;
        array[3]=m4/10;
        int m5 = m4%10;
        array[4]=m5;
        for(int i = 0; i < 5-i; i++)
        {
            int temp = array[i];
            array[i] = array[4-i];
            array[4-i] = temp;
        }
    cout<<array[0]<<"  "<<array[1]<<"  "<<array[2]<<"  "<<array[3]<<"  "<<array[4]<<endl;
    }
}