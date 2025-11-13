#include<bits/stdc++.h>
using namespace std;
void first_line(vector<char>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=='H'||v[i]=='Y')
        {
            cout<<"*     *";
        }
        else if(v[i]=='A')
        {
            cout<<"   *   ";
        }
        else if(v[i]=='P')
        {
            cout<<"* * *  ";
        }
        cout<<" ";
    }
    cout<<endl;
}
void second_line(vector<char>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=='H')
        {
            cout<<"*     *";
        }
        else if(v[i]=='A')
        {
            cout<<"  * *  ";
        }
        else if(v[i]=='P')
        {
            cout<<"*     *";
        }
        else if(v[i]=='Y')
        {
            cout<<" *   * ";
        }
        cout<<" ";
    }
    cout<<endl;
}
void third_line(vector<char>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=='H')
        {
            cout<<"* * * *";
        }
        else if(v[i]=='A')
        {
            cout<<" *   * ";
        }
        else if(v[i]=='P')
        {
            cout<<"* * *  ";
        }
        else if(v[i]=='Y')
        {
            cout<<"  * *  ";
        }
        cout<<" ";
    }
    cout<<endl;
}
void forth_line(vector<char>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=='H')
        {
            cout<<"*     *";
        }
        else if(v[i]=='P')
        {
            cout<<"*      ";
        }
        else if(v[i]=='A')
        {
            cout<<"* * * *";
        }
        else if(v[i]=='Y')
        {
            cout<<"   *   ";
        }
        cout<<" ";
    }
    cout<<endl;
}
void fifth_line(vector<char>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]=='H'||v[i]=='A')
        {
            cout<<"*     *";
        }
        else if(v[i]=='P')
        {
            cout<<"*      ";
        }        
        else if(v[i]=='Y')
        {
            cout<<"   *   ";
        }
        cout<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<char> v;
    char s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }  
    // 调用输出函数
    first_line(v);
    second_line(v);
    third_line(v);
    forth_line(v);
    fifth_line(v); 
    return 0;
}