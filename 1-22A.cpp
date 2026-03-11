#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;string s;cin>>n>>s;
    string rev=s;
    reverse(rev.begin(),rev.end());
    string t=rev+"#"+s;
    int m=t.size();
    vector<int> pi(m,0);
    for (int i=1;i<m;++i) {
        int j=pi[i-1];
        while (j>0&&t[i]!=t[j])j=pi[j-1];
        if (t[i] == t[j])++j;
        pi[i] = j;
    }
    int L = pi[m - 1];
    cout << n - L << endl;
    return 0;
}
