#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 5005;
int s, n, u, v, cnt, dis;
int rt[MM], deg[MM], sum[MM];
vi adj[MM];
bool vis[MM];
vi dia2;
int done;
vector<int> dia;
void dfs(int u, int p, int d){
    if(vis[u]) return;
    if(d==0&&deg[u]>1){
        return;
    }
    if(d>0){
    for(auto e:adj[u]){
        if(e!=p&&!vis[e]){
            dfs(e, u, d-1);
        }
    }
    }
    if(deg[u]<=1){ vis[u] = 1;done++;}
    if(vis[u]){
        for(auto e:adj[u]){
            if(!vis[e]) deg[e]--;
        }
    }

}
void dfs2(int u, int p, int d, int id){
    if(vis[u]) return;
    if(d==0&&deg[u]>1){
        return;
    }
    
    if(deg[u]<=1){ vis[u] = 1;done++;}
    if(vis[u]&&id+1<dia2.size()){
        int e = dia2[id+1];

            if(!vis[e]) deg[e]--;
    }

}
int st, ed, mx, cur;
void find(int x, int p, int cnt){
    if(vis[x]) return;
    if(cnt>mx){
        mx = cnt;
        cur = x;
    }
    for(auto e:adj[x]){
        if(e!=p){
            find(e, x, cnt+1);
        }

    }
}
void store(int u, int p){
    dia.pb(u);
    if(u==ed){
        for(auto e:dia) dia2.pb(e);
        return;
    }
    for(auto e:adj[u]){
        if(e!=p){
            store(e, u);
        }
    }
    dia.pop_back();
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> s;
    FOR(i,1 , n-1){
        cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }
    if(s>=n){
        cout << 0 << "\n";
        return 0;
    }
    int lo = 1, hi = n/2, mid;
    ed = 1;
    while(lo!=hi){
        cnt=0; done = 0;
        memset(vis, 0, sizeof vis);
        mid = (lo+hi)/2;
        FOR(i, 1, n) deg[i] = adj[i].size();
        while(done!=n){
            dia.clear();dia2.clear();
            find(ed, ed, 0);
            st = cur;
            mx = 0;
            find(st, st, 0);
            ed = cur;
            store(st, st);
            int idx = min((ll)mid, (ll)dia2.size()-1);
            int dis = mid;
            
            dfs(dia2[idx], dia2[idx], dis);
            idx++; dis--;
            while(idx < dia2.size()&&vis[dia2[idx-1]]&&dis>=0){
                dfs2(dia2[idx], dia2[idx], dis, idx);
                idx++; dis--;
            }

            cnt++;
        }
        if(cnt<=s){
            hi = mid;
        }
        else lo = mid+1;
        

    }
    cout << lo << "\n";
    return 0;
}