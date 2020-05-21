#include <bits/stdc++.h>

using namespace std;

const int MM = 100005;

typedef pair<int, int> pi;
vector<pair<int,int>> adj[MM];
vector<vector<int>> par(18, vector<int>(MM));
vector<vector<pi>> st(18, vector<pi>(MM, pi{INT_MIN, INT_MIN}));
int lvl[MM];
pi comp(pi u, pi v)
{
    pi ans;
    if (u.first > v.first)
        swap(u, v);
    ans.first = v.first;
    ans.second = max(u.first, v.second);
    return ans;
}



void dfs(int u, int p, int w)
{
    lvl[u] = lvl[p]+1;
    par[0][u] = p;
    st[0][u].first = w;
    st[0][u].second = INT_MIN;
    for (auto e : adj[u])
        if (e.first != p)
            dfs(e.first, u, e.second);
}

void build()
{
    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j < MM; j++)
			int pa = par[i-1][j];
            par[i][j] = par[i-1][pa],
            st[i][j] = comp(st[i-1][j], st[i-1][pa]);
    }
}

int lca(int a, int b)
{
    if (lvl[a] > lvl[b])
        swap(a, b);
    int d = lvl[b]-lvl[a];
    for (int i = 0; i < 18; i++)
        if (d&(1<<i))
            b = par[i][b];
    if (a == b)
        return a;
    for (int i = 17; i >= 0; i--)
        if (par[i][a] != par[i][b]){
            a = par[i][a]; b = par[i][b];}
    return par[0][a];
}

pi query(int a, int c)
{
    int d = lvl[a]-lvl[c];
    pi ans = {INT_MIN, INT_MIN};
    for (int i = 0; i < par.size(); i++)
        if (d&(1<<i))
            ans = comp(ans, st[i][a]), a = par[i][a];
    return ans;
}

int main()
{
    
    for (int i = 1, u, v, w; i < n; i++)
    {
        cin >> u > v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 1, INT_MIN);
    build();
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> u >> v;
		int lc = lca(u, v);
		int ans = comp(query(u, lc), query(v, lc)).second;
        printf("%i\n", ans == INT_MIN ? -1 : ans);
    }
	return 0;
}