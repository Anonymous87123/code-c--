//扩展欧几里得算法，对于方程ax%b=1,等价于存在整数y使得ax+by=1(利用带余除法立即得到),由于题目保证有解，所以a,b互质（裴属定理），先使用该算法得到特解，再用x=(x0%b+b)%b得到正整数解
//如果已知gcd(b,a mod b)的解，可以推出gcd(a,b)的解，假设bx1+(a mod b)y1=gcd(a,b)，则有bx1+(a - floor(a/b)*b)y1=gcd(a,b)，即ay1 + b(x1 - floor(a/b)*y1)=gcd(a,b)，所以x=y1,y=x1 - floor(a/b)*y1
#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int& x,int& y)//a对应x,b对应y
{
    if(b==0)//若b=0,则ax=a,x=1,y=0
    {
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);//递归调用时交换了a,b的位置，所以x,y也要交换
    y-=(a/b)*x;
    return d;
}
int main()
{
    int a,b,x,y;
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<(x%b+b)%b<<endl;
}