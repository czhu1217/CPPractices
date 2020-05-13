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
typedef long long ll;
using namespace std;
const ll MM = 1e6+2;
ll N, K;
ll w[MM], ind[MM], par[MM]; vector<ll> adj[MM];
bool vis[MM], done=0, no[MM];
queue<ll> q;
void find(ll id){
    cout << id << " ";
    if(par[id]==-1)return;
    find(par[id]);
    return;

}
void dfs(ll u, ll sum, ll cnt){
    if(done)return;
    if(sum>=K&&sum<=2*K){
        cout << cnt << "\n";
        find(u);
        done=1;
        return;
    }
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            par[v]=u;
            dfs(v, sum+w[v], cnt+1);
        }
    }
}

int main(){
    cin >> N >> K;ll sum=0;
    memset(no, 0, sizeof no);
    for(ll i=1;i<=N;i++){
        scanf("%lld", &w[i]);
        if(w[i]>=K&&w[i]<=2*K){
            cout << 1 << "\n";
            cout << i << "\n";
            return 0;
        }
        if(w[i]>2*K)no[i]=1;
    }
    for(ll i=1, u, v;i<N;i++){
        scanf("%lld %lld", &u, &v);
        if(w[u]>K||w[v]>K){
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=N;i++){
        if((!no[i])&&(!vis[i])){
            par[i]=-1;
            dfs(i, w[i], 1);
        }
        if(done)return 0;
    }
    cout << -1 << "\n";
    
    return 0;
    

}