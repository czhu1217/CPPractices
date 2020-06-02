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
typedef long long ll;
using namespace std;
const int MM = 1e5+5;
int n, m, rt[MM], milk[MM];
vector<int> adj[MM];
int ans[MM];
void dfs(int u, int p){
    if(milk[u] == milk[p]){
        rt[u] = rt[p];
    }
    else rt[u] = u;
    for(auto e:adj[u]){
        if(e!=p) dfs(e, u);
    }

}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        if(c=='H')milk[i] = 1;
        else milk[i] = 0;
    }
    for(int i=1, u, v;i<n;i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    rt[1] = 1;
    dfs(1, 0);
    for(int i=1, u, v;i<=m;i++){
        cin >> u >> v;
        char c; cin >> c;
        if(rt[u]!=rt[v]) ans[i] = 1;
        else if(c=='H'){
            if(milk[u]) ans[i] = 1;
            else ans[i]=0;
        }
        else{
            if(!milk[u])ans[i] = 1;
            else ans[i] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}