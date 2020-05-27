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
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 1e5+2, LOG=17, MV=1e9;
int n, dep[MM], anc[LOG][MM]; int mi[MM], q;
struct ed{
    int l, r, v, i;
    bool operator<(const ed &e){
        return l==e.l?r<e.r:l<e.l;
    }
} a[MM], ori[MM];
vector<int> adj[MM];
int min_dis(int u, int v){

    if(ori[u].v>ori[v].v) swap(u, v);
    return u;
}
int lca(int u, int v){
    if(dep[u]<dep[v])swap(u, v);
    for(int i=LOG-1;i>=0;i--){
        if(dep[anc[i][u]]>=dep[v]) u = anc[i][u];
    }
    if(u==v)return u;
    for(int i=LOG-1;i>=0;i--){
        if(anc[i][u]!=anc[i][v]){
            u = anc[i][u]; v = anc[i][v];
        }
    }
    return anc[0][u];
}
void dfs(int u, int p){
    mi[u] = min_dis(mi[p],u);
    dep[u] = dep[p]+1;
    anc[0][u] = p;
    for(auto e:adj[u]){
        if(e!=p) dfs(e, u);
    }
}
void build(){
    for(int i=1;i<LOG;i++){
        for(int j=0;j<=n;j++){
            int p = anc[i-1][j];
            anc[i][j] = anc[i-1][p];
        }
    }
}
int main(){
    cin >> n;
    a[0] = {0, MV+1, MV+1, 0};
    ori[0] = {0, MV+1, MV+1, 0};
    FOR(i, 1, n){
        cin >> a[i].l >> a[i].r >> a[i].v;
        a[i].i = i;
        ori[i].l=a[i].l,ori[i].r=a[i].r;ori[i].v=a[i].v;
    }
    sort(a, a+1+n);
    vector<pi> v;
    v.push_back({0, a[0].r});
    FOR(i, 1, n){
        if(!v.empty()){
            while((!v.empty())&&v.back().s<a[i].r){ v.pop_back();}
            adj[v.back().f].push_back(a[i].i);
            adj[a[i].i].push_back(v.back().f);

        }
        v.push_back({a[i].i, a[i].r});
    }

    dfs(0, 0);
    build();
    cin >> q;
    for(int i=1;i<=q;i++){
        int ai, b; cin >> ai >> b;
        int lc = lca(ai, b);
        if(lc==ai||lc==b) lc = anc[0][lc];
        if(lc<=0) cout << -1 << "\n";
        else cout << mi[lc] << "\n";
    }
    return 0;
}