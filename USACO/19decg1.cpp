#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
typedef  long long ll;
typedef pair<int, int> pi;
#define fi first;
#define s second;
int N, M, mul = 1e6;
struct pipe{
    int v, c, f;
}p[1002];
bool vis[1002];
struct pth{ 
    int u, par; int tot, minf;
    bool operator<(const pth &e){
        return minf/tot*1.0>e.minf/e.tot*1.0;
    }
};
vector<pipe> adj[100005];
deque<pth> qu;
int main(){
    memset(vis, 0, sizeof(vis));
    cin >> N >> M;
    for(int i=1, a, b, c, f;i<=M;i++){
        scanf("%d %d %d %d", &a, &b, &c, &f);
        f *= mul;
        adj[a].push_back({b,  c, f});
        adj[b].push_back({a,  c, f});
        if(a==1){
            pth p = {b, a, c, f};
            qu.push_back(p);
        }
        if(b==1) qu.push_back({a, b, c, f});
    }
    while(!qu.empty()){
        int u = qu.front().u, cost = qu.front().tot, minFlow = qu.front().minf, par = qu.front().par;
        qu.pop_front();
        vis[u]=true;
        if(u==N){
            cout << minFlow/cost << "\n";
            return 0;
        } 
        for(auto e:adj[u]){
            if(e.v!=par&&!vis[e.v]){
                qu.push_back({e.v, u, cost+e.c, min(minFlow, e.f) });
            }
        }
        sort(qu.begin(),qu.end());
    }
    return 0;
    
}

