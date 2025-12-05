#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ax,ay,bx,by,cx,cy,dx,dy;
    while(cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy)
    {
        if(
            (bx-ax)*(bx-cx)+(by-ay)*(by-cy)==0 &&
            (cx-bx)*(cx-dx)+(cy-by)*(cy-dy)==0 &&
            (dx-cx)*(dx-ax)+(dy-cy)*(dy-ay)==0 &&
            (ax-dx)*(ax-bx)+(ay-dy)*(ay-by)==0 &&
            (bx-ax)*(bx-dx)+(by-ay)*(by-dy)==(bx-cx)*(bx-cx)+(by-cy)*(by-cy) 
        )
        {
            cout<<"Square"<<endl;
        }
        else if(
            (bx-ax)*(bx-cx)+(by-ay)*(by-cy)==0 &&
            (cx-bx)*(cx-dx)+(cy-by)*(cy-dy)==0 &&
            (dx-cx)*(dx-ax)+(dy-cy)*(dy-ay)==0 &&
            (ax-dx)*(ax-bx)+(ay-dy)*(ay-by)==0 
        )
        {cout<<"Rectangle"<<endl;}
        else cout<<"Other Quadrilateral"<<endl;
    }
}