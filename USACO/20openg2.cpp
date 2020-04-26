#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <fstream>
#include <queue>
#include <unordered_map>

using namespace std;
const int MM = 2e5+5;
typedef long long ll;
int N, M, par[MM], a[MM], cnt; vector<int> adj[MM];
int pa(int d){
    return d==par[d]?par[d]:par[d] = pa(par[d]);
}
void dfs(int u){
    if(adj[u].size()<=1)return;
    int rt = pa(adj[u][0]);
    while(adj[u].size()>1){
         int rv = pa(adj[u].back()); adj[u].pop_back();
         if(rt==rv)continue;
        if(adj[rt].size()<adj[rv].size()) swap(adj[rt], adj[rv]);
        par[rv] = rt; adj[rt].insert(adj[rt].end(), adj[rv].begin(), adj[rv].end());

    }
    dfs(rt);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++)par[i]=i;
    for(int i=1, u, v;i<=M;i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);

    }
    for(int i=1;i<=N;i++)dfs(i);
    for(int i=1;i<=N;i++){
        int rt = pa(i);
        if(a[rt]==0)a[rt]=++cnt;
        cout << a[rt] << "\n";

    }
    return 0;

}