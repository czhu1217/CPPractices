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
typedef long long ll;
using namespace std;
#define f first
const int MM = 1e5+5;
typedef pair<int, int> pi;
int ans = 0;
int n, sz[MM]; vector<pi> adj[MM]; char c; bool done[MM];
unordered_map<int, int> mp;
void getsz(int u, int pre){
    sz[u] = 1;
    for(pi e:adj[u]){
        if(e.first!=pre&&done[e.first]){
            getsz(e.first, u);
            sz[u]  += sz[e.first];

        }
    }

}
int getcent(int u, int pre, int tot){
    for(pi e:adj[u]){
        if(e.first !=pre && !done[e.first]&&sz[e.f]*2>tot){
            return getcent(e.f, u, tot);
        }
    }
}
void dfs(int u, int pre, int sum, vector<int>& path){
    path.push_back(sum);
    ans += mp[1-sum] + mp[-1-sum];
    for(auto e: adj[u]){
        if(e.f!=pre&&!done[e.f]){
            dfs(e.f, u, sum+e.second, path);
        }


    }

}
void solve(int rt){
    getsz(rt, -1);
    rt = getcent(rt, -1, sz[rt]);
    done[rt] = true;
    mp.clear(); mp[0] = 1;
    for(auto e:adj[rt]){
        int v = e.f, w = e.second;
        if(!done[v]){
            vector<int> path; dfs(v, rt, w, path);
            for(int x:path) mp[x]++;
        }

    }

}
int main(){
    scanf("%d", &n);
    for(int i=1, u, v, w; i<n;i++){
        scanf("%d %d %c", &u, &v, &c);
        w = (c=='r'?1:-1);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    solve(1);
}