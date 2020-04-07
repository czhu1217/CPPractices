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
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5+5;
int N, sz[MM], lvl[MM], pa[MM]; 
bool vis[MM];
ll dis[19][MM], tot = INT_MAX;
vector<pi> adj[MM]; bool done[MM];
int ans[MM];
void getsz(int u, int pa){
    sz[u]= 1;
    for(pi e:adj[u]){
        if(e.first!=pa&&!done[e.first]){
            getsz(e.first, u);
            sz[u]+= sz[e.first];
        }
    }
}
int getcent(int u, int pa, int tot){
    for(auto e:adj[u]){
        if(e.first != pa&&!done[e.first]&&sz[e.first]*2>tot){
            return getcent(e.first, u, tot);
        }
        return u;
    }
}
void dfs(int u, int level, int sum){
    dis[level][u] = sum;
    for(auto e:adj[u]){
        if(!done[e.first]) dfs(e.first, level, sum+e.second);
    }
}

void solve(int rt, int pre, int level){
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]);
    done[rt]=1;lvl[rt]=level;pa[rt]=pre;
    dfs(rt, lvl[rt], 0);
    for(pi e:adj[rt])
    if(!done[e.first]) solve(e.first, rt, level+1);

}
void Init(int n, int A[], int B[], int D[]){
    N = n;
    for(int i=0;i<N-1;i++){
        adj[A[i]].push_back({B[i], D[i]}); adj[B[i]].push_back({A[i],D[i]});
    }
    solve(1, -1, 0);


}
long long Query(int S, int X[], int T, int Y[]){
    ll tot = INT_MAX; 
    memset(vis, 0, sizeof vis);
    memset(ans, 0x3f, sizeof ans);
    for(int i=1;i<=S;i++){
        int u = X[i]; int lv=lvl[u];
        vis[u] = true;
        while(lvl>0){
            int v = pa[u];
            vis[v]=true;
            if(dis[lv-1][u]+ans[u]<ans[v]){
                ans[v] = dis[lv-1][u]+ans[u];
                u=v;
            }
            else break;
            lv--;
        }
    }
    for(int i=1;i<=T;i++){
        int u = Y[i];int lv=lvl[u];
        while(lv>0){
            int v = pa[u];
            if(ans[u]+ans[v]<tot) tot=ans[u]+ans[v];
            if(!vis[v]&&dis[lv-1][u]+ans[u]<ans[v]){
                ans[v]=dis[lv-1][u]+ans[u];
                u=v;
            }
            else break;
            lv--;
        }
    }
    return tot;
}
