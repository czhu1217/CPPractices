#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
long long mn = INT_MAX;
vector<int> adj[300002];
vector<int> leaf;
int cost[300002];
int n, m;
int dfs(int par, int node)
{
    if(adj[node].size()==0) return cost[node];
    int ans = INT_MAX;
    for(auto e:adj[node]){
        ans = min(ans, dfs(node, e));
    }
    cost[node] += ans;
    return cost[node];
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0, rt, num; i < m; i++)
    {
        cin >> rt >> num;
        for (int j = 0, x; j < num; j++)
        {
            cin >> x;
            adj[rt].push_back(x);
        }
    }

    for (int i = 1, x; i <= n; i++)
    {
        cin >> cost[i];
    }
    dfs(-1, 1);
    cout << cost[1] << endl;

    return 0;
}