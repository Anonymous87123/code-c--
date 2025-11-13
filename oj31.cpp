#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<int>> all(2);
    for(int i=0;i<n;i++)
    {
        for(int k=1;k<=2;k++)
        {
            int length;cin>>length;
            vector<int> temp(length);
            for(int j=0;j<length;j++)
            {
                cin >> temp[j];
                all[i].push_back(temp[j]);
            }
        }
        sort(all[i].begin(),all[i].end());
    }
    for(int i=0;i<2;i++)
    {
        cout<<all[i].size()<<" ";
        for(auto& n:all[i])
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
}