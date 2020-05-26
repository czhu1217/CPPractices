#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
int l, s, e, n, len[5005];
vector<int> adj[5005];
bool vis[5005];
int main(){
    memset(vis, 0, sizeof vis);
    cin >> l >> s >> e >> n;
    for(int i=1, u, v;i<=n;i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(s);
    len[s]=0; vis[s]=1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u==e){cout << len[u] << "\n"; 
        return 0;}
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                len[v] = len[u]+1;
                q.push(v);
            }
        }
    }
}