#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
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
const int MM = 5005;
int n, m, disa[MM], disb[MM], fir, sec=INT_MAX; bool vis[MM];
vector<pi> adj[MM];
void dij1(int u){
    int w;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, u});
    while(!q.empty()){
        u = q.top().s; w = q.top().f; q.pop(); 
        if(vis[u]) continue;
        disa[u] = w;
        vis[u] = 1;
        for(auto e:adj[u]){
            if(!vis[e.f]){
                q.push({e.s+w, e.f});
            }
        }

    }
}
void dij2(int u){
    memset(vis, 0, sizeof vis);
    int w;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, u});
    while(!q.empty()){
        u = q.top().s; w = q.top().f; q.pop();
        if(vis[u]) continue; 
        disb[u] = w;
        vis[u] = 1;
        for(auto e:adj[u]){
            if(!vis[e.f]){
                q.push({e.s+w, e.f});
            }
        }

    }
}
int main(){
    memset(disa, 0x3f, sizeof disa); memset(disb, 0x3f, sizeof disb);
    cin >> n >> m;
    int a, b, c;
    FOR(i, 1, m){
        cin >> a >> b >> c;
        adj[a].pb({b, c}); adj[b].pb({a, c});
    }
    dij1(1); dij2(n);
    fir = disa[n];
    int w;
    for(int i=1;i<=n;i++){
        for(auto e:adj[i]){
            a = i, b = e.f, w = e.s;
            if(disa[a]+w+disb[b]<sec&&disa[a]+w+disb[b]>fir){
                sec = disa[a]+w+disb[b];
            }
            if(disa[b]+w+disb[a]<sec&&disa[b]+w+disb[a]>fir){
                sec = disa[b]+w+disb[a];
            }
        }
    }
    cout << sec << "\n";
    return 0;
}