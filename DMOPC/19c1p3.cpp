#include<bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 3e5+2, MM = 3e3+2, MOD = 1e9+7, BASE = 131;
vector<pii> adj[MN];
bool neg[MN], vis[MN];
int val[MN], l, r, k;
void check (int a, int b, int c) {
    if (neg[a] == neg[b]) {
        int sol = (val[a] + val[b] - c)/2;
        if (!neg[a]) sol = -sol;
        l = max(l,sol); r = min(r,sol);
    } else {
        if (val[a]+val[b] != c) r = 0, l = k+1;
    }
}
void dfs (int cur) {
    vis[cur] = 1;
    if (neg[cur]) l = max(l,val[cur]-k), r = min(r,val[cur]-1);
    else  l = max(l,1-val[cur]), r = min(r,k-val[cur]);
    for (pii p : adj[cur]) {
        if (vis[p.first]) {check(cur,p.first,p.second); continue;}
        neg[p.first] = !neg[cur];
        val[p.first] = p.second - val[cur];
        dfs(p.first);
    }
}
int main () {
    int n,m,a,b,c; ll ans = 1;
    scan(n); scan(m); scan(k);
    while (m--) {
        scan(a); scan(b); scan(c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]){
        l = 1, r = k;
        dfs(i);
        if (r < l) return !printf ("0\n");
        else ans = ans * (r-l+1) % MOD;
    }
    printf ("%lld\n",ans);
    return 0;
}