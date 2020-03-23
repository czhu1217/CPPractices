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
using namespace std;
#define f first;
#define s second;
const int MM = 1e5+5;
typedef pair<int, int> pi;
typedef long long ll;
int N, sz[MM], val[2][2*MM], path[2*MM];
vector<pi> adj[MM]; bool done[MM]; ll ans;
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
void dfs1(int u, int sum, int pa){
    path[sum]++; ans+=val[1];
}
void solve(int rt){
    getsz(rt, 0);
    rt = getcent(rt, 0, sz[rt]);done[rt] = true;
    for(int i=-sz[rt]+N;i<=sz[rt]+N;i++) path[i] = val[0][i] = val[1][i] = 0;
    val[0][N]=1;
    for(pi e:adj[rt]){
        int v = e.first, w = e.s; 
        if(!done[v]){
            path[N] = 0;
            dfs1(v, w, rt);
        }
    }
    for(pi e:adj[rt]){
        if(!done[e.first]) solve(e.first);
    }
}
