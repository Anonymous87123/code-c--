#include<iostream>
using namespace std;
int main()
{
    int count = 0;
    long long sum = 0;
    for (int i1 = 0; i1 < 10; i1++)
    for (int i2 = 0; i2 < 10; i2++)
    for (int i3 = 0; i3 < 10; i3++)
    for (int i4 = 0; i4 < 10; i4++)
    for (int i5 = 0; i5 < 10; i5++)
    for (int i6 = 0; i6 < 10; i6++)
    for (int i7 = 0; i7 < 10; i7++)
    for (int i8 = 0; i8 < 10; i8++)
    for (int i9 = 0; i9 < 10; i9++)
    {
        if (i1+i2+i3+i4+i5+i6+i7+i8+i9 == 45 && i1*i2*i3*i4*i5*i6*i7*i8*i9 == 1*2*3*4*5*6*7*8*9)
        {count++;sum+=count;}
    }
    cout << count << endl;
    cout << sum << endl;
}
