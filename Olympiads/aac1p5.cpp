#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 2e5+5;
int n, x, y, z, dis[MM], od, ev, ch[MM][2];
vector<pi> adj[MM];
ll totod, totev;
void dfs(int u, int p){
    if(dis[u]%2) od++; else ev++;
    for(auto e:adj[u]){
        if(e.f!=p){
            dis[e.f] = dis[u] + e.s;
            dfs(e.f, u);
            ch[u][0] += ch[e.f][0];
            ch[u][1] += ch[e.f][1];

        }
    }
    ch[u][dis[u]%2]++;
}
ll ans=0;
int main(){
    cin >> n;
    FOR(i, 1, n-1){
        cin >> x >> y >> z;
        adj[x].pb({y, z%2}); adj[y].pb({x, z%2});
    }
    dfs(1, 1);
    totod = ev*od;
    totev = od*(od-1)/2 + ev*(ev-1)/2;
    // cout << totod << " " << totev << "\n";
    ans = abs(totod-totev);
    FOR(i, 1, n){
        int odd, even;
        odd = od - ch[i][1] + ch[i][0];
        even = ev - ch[i][0]+ch[i][1];
        totod = even*odd;
        totev = odd*(odd-1)/2 + even*(even-1)/2;
        ans = min(ans, abs(totod-totev));
    }
    cout << ans << "\n";
    // FOR(i, 1, n) cout << dis[i] << " ";


    return 0;
}