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
int n, q; unsigned int dis[6005][6005];
vector<pair<int, int>> adj[6005];
void dfs(int s, int i, int prev, int dist){
    dis[s][i] = dist;
    for(auto e:adj[i]){
        if(e.first!=prev){
            dfs(s, e.first, i, dist+e.second);
        }
    }
}
int main(){
    cin >> n;
    for(int i=1, a, b, w;i<n;i++){
        scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    for(int i=0;i<n;i++){
        dfs(i, i, -1, 0);
    }
    cin >> q; int u, v;
    for(int i=0;i<q;i++){
        scanf("%d %d", &u, &v);
        cout << dis[u][v] << "\n";
    }



}
