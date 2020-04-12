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
const int MM = 5e5+5;
int N, sz[MM], lvl[MM], pa[MM];
ll dis[19][MM], tot = LLONG_MAX;
vector<pi> adj[MM]; bool done[MM];
ll ans[MM];
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

    }
    return u;
}
void dfs(int u, int pre,int level, ll sum){
    dis[level][u] = sum;
    for(auto e:adj[u]){
        if(!done[e.first]&&e.first!=pre) dfs(e.first,u, level, sum+e.second);
    }
}

void solve(int rt, int pre, int level){
    getsz(rt, -1); rt = getcent(rt, -1, sz[rt]);
    done[rt]=1;lvl[rt]=level;pa[rt]=pre;
    dfs(rt,-1, lvl[rt], 0);
    for(pi e:adj[rt])
    if(!done[e.first]) solve(e.first, rt, level+1);

}
void Init(int n, int A[], int B[], int D[]){
    memset(ans, 0x3f, sizeof ans);
    N = n; 
    for(int i=0;i<N-1;i++){
        adj[A[i]].push_back({B[i], D[i]}); adj[B[i]].push_back({A[i],D[i]});
    }
    solve(0, -1, 0);


}
long long Query(int S, int X[], int T, int Y[]){
    tot = LLONG_MAX; 
    for(int i=0;i<S;i++){
        for(int v=X[i], u=X[i];u!=-1;u=pa[u]){
            ans[u] = min((ll)ans[u], dis[lvl[u]][v]);
        }
    }
    for(int i=0;i<T;i++){
        for(int v=Y[i], u=Y[i];u!=-1;u=pa[u]){
            tot = min(tot, ans[u]+dis[lvl[u]][v]);
        }
    }
    for(int i=0;i<S;i++){
        for(int v=X[i], u=X[i];u!=-1;u=pa[u]){
            ans[u] = LLONG_MAX;
        }
    }

    return tot;
}
