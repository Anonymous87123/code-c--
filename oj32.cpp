#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.first!= b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main()
{
    vector<vector<pair<int,int>>> arr;
    int m;
    while(cin>>m)
    {
        vector<pair<int,int>> temp(m);
        for(int i=0;i<m;i++)
        {
            cin >> temp[i].first;
            temp[i].second = i;
        }
        sort(temp.begin(),temp.end(),compare);
        arr.push_back(temp);
    }
    for(auto& x:arr)
    {
        cout<< x[0].first << " "<< x[0].second <<endl;
    }
}