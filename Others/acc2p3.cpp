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
vector<pi> adj[MM]; int lvl[MM];
int par[MM2][MM*2+1]; pi st[MM2][MM*2+1];
pi comp(pi a, pi b){
    pi e;
    if(a.f<b.f)swap(a, b);
    e.f = a.f;
    e.s = max(a.s, b.f);
    return e;
}

pi query(int u, int v){
    int d = lvl[u]-lvl[v];
    pi ans = {INT_MIN, INT_MIN};
    for(int i=0;i<MM2;i++){
        if((1<<i)&d){
            ans = comp(ans, st[i][u]); 
            u = par[i][u];
        }
    }
    return ans;
    


}
void dfs(int u, int p, int w){
    lvl[u] = lvl[p]+1;
    par[0][u] = p;
    st[0][u].f = w; st[0][u].s=INT_MIN;
    for(auto e:adj[u]){
        if(e.f!=p){

             dfs(e.f, u, e.s);

        }
    }
}

void build(){
    for(int i=1;i<MM2;i++){
        for(int j=1;j<=n;j++){
            int pa = par[i-1][j];
                par[i][j] = par[i-1][pa];
                st[i][j] = comp(st[i-1][j], st[i-1][pa]);

        }
    }
}

int lca(int u, int v){
    if(lvl[u]<lvl[v])swap(u, v);
    int dif = lvl[u]-lvl[v];
    for(int i=0;i<MM2;i++){
        if(dif&(1<<i)) u = par[i][u];

    }        
    if(u==v)return u;
    for(int i=MM2-1;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            u = par[i][u]; v=par[i][v];
    }
    }
    return par[0][u];
}



int main(){
    cin >> n;
    for(int i=0, u, v, w;i<n-1;i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});adj[v].push_back({u, w});
    }
    dfs(1, 1, INT_MIN);
    build();
    cin >> q;
    for(int i=0, u, v;i<q;i++){
        cin >> u >> v;
        int p = lca(u, v);
        int ans = comp(query(u, p), query(v, p)).s;
        if(ans==INT_MIN)ans=-1;
        cout << ans << "\n";
    }
    return 0;


}