#include <iostream>
using namespace std;
int main() 
{
    int count = 0;
    for (int a = 0; a <= 20; ++a)
    for (int b = 0; b <= 20; ++b)
    for (int c = 0; c <= 20; ++c)
    for (int d = 0; d <= 20; ++d)
    {if (a + b + c + d == 20 && (a==4 || b==4 || c==4 || d==4) && min(a, min(b, min(c, d)))>=1){count++;}
    }
    cout << count << endl;
    return 0;
}



