#include<iostream>
using namespace std;
int main()
{
    cout<<"请你想好一个1~1000之内的整数，别告诉我，让我来猜猜！"<<endl;
    cout<<"猜中了，请输入0；若猜的数小了， 请输入-1；若猜的数大了，请输入1"<<endl;
    cout<<"开始猜了……"<<endl;
    int guess=500;int m;int inf=1;int sup=1000;
    cout<<"是 500 吗？"<<endl;
    cin>>m;int count=1;
    while(m!=0)
    {
        count++;
        if(m==1)
        {
            sup=guess-1;
            if(sup==inf){cout<<"是 "<<guess<<" 吗？"<<endl;cin>>m;}else{
            guess=(inf+sup-0.1)/2;
            cout<<"是 "<<guess<<" 吗？"<<endl;
            cin>>m;
        }}
        if(m==-1)
        {
            inf=guess+1;
            if(sup==inf){cout<<"是 "<<guess<<" 吗？"<<endl;cin>>m;}else{
            guess=(inf+sup+0.1)/2;
            cout<<"是 "<<guess<<" 吗？"<<endl;
            cin>>m;
        }}
    }
    if(m==0){cout<<"我猜中啦！只猜了 "<<count<<" 次，很强吧！";}
}