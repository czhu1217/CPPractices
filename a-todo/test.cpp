
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n, q, u, v, bw;

const int MM = 3e5+2, B_MAX = 20, mod=998244353;
int ind[MM], lv[MM];

int st[B_MAX][MM * 2 + 1], cnt = 1; 

vector<int> adj[MM];
ll quick_pow(ll x, ll exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t%mod;
    return (exp&1)?t*x%mod:t;
}
inline int dist_min(int a, int b){
	return lv[a] < lv[b] ? a : b;
}

int query(int a, int b){ 
	a = ind[a];
	b = ind[b];

	if(a >= b){
		swap(a, b);
	}

	int d = b - a, mx = 1,mxidx = 0; 

	for (int i = B_MAX; i >= 0; --i) {
		int v = 1 << i;

		if(d & v){
			mx = v;
			mxidx = i;
			break;
		}
	}

	return dist_min(st[mxidx][a],
			st[mxidx][b - mx + 1]);
}

void dfs(int cur, int lvl, int parent){
	st[0][cnt++] = cur;
	lv[cur] = lvl;

	for(auto adj : adj[cur]){
		if(adj != parent){
			dfs(adj, lvl + 1, cur);
			st[0][cnt++] = cur;
		}
	}
}

void build(){
	dfs(1, 0, -1);
	for (int i = 1; i <= cnt; ++i) {
		if(!ind[st[0][i]]){
			ind[st[0][i]] = i;
		}
	}
	for (int i = 1; i < B_MAX; ++i) {
		int gap = 1 << (i - 1), maxv = cnt - (1 << i) + 1;

		for (int j = 1; j <= maxv; ++j) {
			st[i][j] = dist_min(st[i - 1][j],
					st[i - 1][j + gap]);
		}
	}
}

int main(){


	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	build();

	cin >> q;
    int k;
	for (int i = 1; i <=q;i++) {
		cin >> u >> v >> k;
        ll sum=0;
		int lca = query(u, v);
        for(int i=lv[u];i>=lv[lca];i--){
            sum  = (sum+quick_pow(i, k))%mod;
        }
        for(int i=lv[v];i>=lv[lca];i--) sum = (sum+quick_pow(i, k))%mod;
        sum = (sum-quick_pow(lv[lca], k)+mod)%mod;
        cout << sum << "\n";

		
	}
    return 0;
}