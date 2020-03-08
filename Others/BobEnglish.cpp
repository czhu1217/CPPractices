//Centroid decomposition of tree
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5 + 5;
int cnt[MM];
ll ans = 0;
vector<pi> adj[MM];
int k, n;
ll sz[MM];
void findsz(int u, int par)
{
    sz[u] = cnt[u];
    for (auto e : adj[u])
    {
        int v = e.first;
        if (v != par)
        {
            findsz(v, u);
            sz[u] += sz[v];
        }
    }
}
int findCentre(int u, int par)
{
    for (pi e : adj[u])
    {
        int v = e.first;
        if (v != par)
        {
            if (sz[v] * 2 > k)
            {
                return findCentre(v, u);
            }
        }
    }
    return u;
}
void dfs(int u, int par, int d)
{
    ans += (ll)cnt[u] * d;
    for (pi e : adj[u])
    {
        int v = e.first, w = e.second;
        if (v != par)
        {
            dfs(v, u, d + w);
        }
    }
}
int main()
{
    scanf("%d %d", &k, &n);
    for (int i = 0, x; i < k; i++)
    {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 0, u, v, w; i < n - 1; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    findsz(1, -1);
    int cen = findCentre(1, -1);
    dfs(cen, 0, 0);

    printf("%lld", ans);
    return 0;
}
