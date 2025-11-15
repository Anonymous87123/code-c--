#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> mar(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> mar[i][j];
            }
        }
        vector<int> row_max(n);
        for(int i = 0; i < n; i++)
        {
            row_max[i]=*max_element(mar[i].begin(),mar[i].end());
        }
        vector<vector<int>> mar_T(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mar_T[j][i]=mar[i][j];
            }
        }
        vector<int> col_min(n);
        for(int i = 0; i < n; i++)
        {
            col_min[i]=*min_element(mar_T[i].begin(),mar_T[i].end());
        }
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mar[i][j]==row_max[i]&&mar[i][j]==col_min[j])
                {
                    flag=true;
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        if(!flag)
        {
            cout<<"没有鞍点"<<endl;
        }
    }
}