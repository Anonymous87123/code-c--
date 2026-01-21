#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int INF=1e18;
int a[N];
int pre[N];
int l[N],r[N];
signed main(){
    int n;
    cin>>n;
    int total=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        total += a[i];
        pre[i] = pre[i-1] + a[i];
    }
    vector<int> left_max(n+2, -INF), right_max(n+2, -INF);
    int cur_max = 0, best_max = -INF;
    for(int i=1;i<=n;i++){
        cur_max = max(a[i], cur_max + a[i]);
        best_max = max(best_max, cur_max);
        left_max[i] = best_max;
    }
    cur_max = 0, best_max = -INF;
    for(int i=n;i>=1;i--){
        cur_max = max(a[i], cur_max + a[i]);
        best_max = max(best_max, cur_max);
        right_max[i] = best_max;
    }
    int ans1 = -INF;
    for(int i=1;i<n;i++){
        ans1 = max(ans1, left_max[i] + right_max[i+1]);
    }
    vector<int> left_min(n+2, INF), right_min(n+2, INF);
    int cur_min = 0, best_min = INF;
    for(int i=1;i<=n;i++){
        cur_min = min(a[i], cur_min + a[i]);
        best_min = min(best_min, cur_min);
        left_min[i] = best_min;
    }
    cur_min = 0, best_min = INF;
    for(int i=n;i>=1;i--){
        cur_min = min(a[i], cur_min + a[i]);
        best_min = min(best_min, cur_min);
        right_min[i] = best_min;
    }
    int min_two_sum = INF;
    for(int i=1;i<n;i++){
        if(!(left_min[i] == pre[i] - pre[0] && 
             right_min[i+1] == pre[n] - pre[i])){
            min_two_sum = min(min_two_sum, left_min[i] + right_min[i+1]);
        }
    }
    int ans2 = -INF;
    if(min_two_sum != INF){
        ans2 = total - min_two_sum;
    }
    bool allneg = true;
    for(int i=1;i<=n;i++){
        if(a[i] > 0){
            allneg = false;
            break;
        }
    }
    if(allneg){
        sort(a+1, a+n+1, greater<int>());
        cout << a[1] + a[2] << endl;
    }else{
        cout << max(ans1, ans2) << endl;
    }
}