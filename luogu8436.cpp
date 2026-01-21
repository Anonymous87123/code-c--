#include <bits/stdc++.h>
using namespace std;
const int MAXN=500001;
int n, m, u, v, cnt;
int dfn[MAXN], low[MAXN];
vector<pair<int, int>> graph[MAXN];
vector<vector<int>> ans;
stack<int> stk;

void tarjan(int x, int las){
	low[x] = dfn[x] = ++cnt;
	stk.push(x);
	for (auto i: graph[x]){
		if (i.second == (las ^ 1)) continue;
		if (!dfn[i.first]){
			tarjan(i.first, i.second);
			low[x] = min(low[x], low[i.first]);
		}else low[x] = min(low[x], dfn[i.first]);
	}
	if (dfn[x] == low[x]){
		vector<int> vec;
		vec.push_back(x);
		while (stk.top() != x){
			vec.push_back(stk.top());
			stk.pop();
		}
		stk.pop();
		ans.push_back(vec);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i(1); i<=m; ++i){
		cin >> u >> v;
		graph[u].push_back(make_pair(v, i<<1));
		graph[v].push_back(make_pair(u, i<<1|1));
	}
	for (int i(1); i<=n; ++i){
		if (!dfn[i]) tarjan(i, 0);
	}
	
	cout << ans.size() << '\n';
	for (auto i: ans){
		cout << i.size() << ' ';
		for (auto j: i) cout << j << ' ';
		cout << '\n';
	}
	return 0;
}