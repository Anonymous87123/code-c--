#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;int new_n=0;
    cin>> n;
    vector<char> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        if(vec[i]=='G'){new_n+=2;}
        else{new_n++;}
    }
    vector<char> new_vec;
    for(int i=0;i<n;i++)
    {
        if(vec[i]=='G'){new_vec.push_back('M');}
    }

}