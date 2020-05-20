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
typedef pair<int, int> pi;
int n, q;
#define f first
#define s second
const int MM = 1e5+3, MM2 = 18;
vector<pair<int, int>> adj[MM];
pi st[MM2][MM*2+1]; int  par[MM2][2*MM+1]; int lvl[MM];

pi comp(pi a, pi b){
    pi e;
    if(a.f<b.f)swap(a, b);
    e.f = a.f;
    e.s = max(a.s, b.f);
    return e;
}

pi query(int u, int v){
    if(u>v)swap(u, v); int mx, mxidx;
    int d = v-u;
    for(int i=MM2;i>=0;i--){
        if((1<<i)&d){
            mx = 1<<i; mxidx = i; break;
        }
    }
    


}
void dfs(int u, int p, int lv){
    lvl[u] = lv;
    for(auto e:adj[u]){
        if(e.f!=p){
            par[0][e.f] = u;
            st[0][e.f].f = e.second;
             dfs(e.f, u, lv+1);

        }
    }
}

void build(){
    for(int i=1;i<MM2;i++){
        for(int j=1;j<=n;j++){
            int pa = par[i-1][j];
            if(pa!=-1){
                par[i][j] = par[i-1][pa];
                st[i][j] = comp(st[i-1][j], st[i-1][pa]);
            }
        }
    }

int find(int u, int v){
    if(lvl[u]>lvl[v])swap(u, v);
    int d = v-u;
    for(int i=MM2-1;i>0;i--){
        if(lvl[par[i][u]]>=lvl[v]&&par[i][u]!=-1) u = par[i][u];
        if(u==v)return u;
    }
    for(int i=MM2;i>=0;i--){
        if(u!=v&&par[i][u]!=-1&&par[i][v]!=-1)[
            u = par[i][u]; v=par[i][v];
        ]
    }
    return par[0][u];
}


}
int main(){
    cin >> n;
    for(int i=0, u, v, w;i<n-1;i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});adj[v].push_back({u, w});

    }
    dfs(1, -1, 0);
    build();
    cin >> q;
    for(int i=0, u, v;i<q;i++){
        cin >> u >> v;
        int lca = find(u, v);
        cout << query(u, v) << "\n";
    }
    return 0;


}