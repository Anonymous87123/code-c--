#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    const int color = 5;
    for (int c1 = 1; c1 <= color; c1++)
    for (int c2 = 1; c2 <= color; c2++)
    for (int c3 = 1; c3 <= color; c3++)
    for (int c4 = 1; c4 <= color; c4++)
    for (int c5 = 1; c5 <= color; c5++)
    for (int c6 = 1; c6 <= color; c6++)
    for (int c7 = 1; c7 <= color; c7++)
    for (int c8 = 1; c8 <= color; c8++){
        if (c1 != c2 && c1 != c4 && c1 != c5 &&
            c2 != c1 && c2 != c3 && c2 != c6 &&
            c3 != c2 && c3 != c4 && c3 != c7 &&
            c4 != c1 && c4 != c3 && c4 != c8 &&
            c5 != c1 && c5 != c6 && c5 != c8 &&
            c6 != c5 && c6 != c2 && c6 != c7 &&
            c7 != c6 && c7 != c3 && c7 != c8 &&
            c8 != c7 && c8 != c4 && c8 != c5)
        {count++;}
    }
    cout << count << endl;
}