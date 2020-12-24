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
int n, a[102];
int rt[102], child[102], cnt;bool vis[102];
vector<int> v[102];
int main(){
    memset(vis, 0, sizeof vis);
    cin >> n ;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        if(!rt[i]){
            rt[i] = i;
        }
        if(rt[a[i]]!=a[i]){
            cout << i << "\n";
             rt[a[i]] = i;
        child[i] = a[i];}

    }
    for(int i=1;i<=n;i++){
        if(rt[i]==i&&child[i]){
            cnt++;
            v[cnt].pb(i);
            int t = child[i];
            while(t){
                v[cnt].pb(t);
                t = child[t];
            }
        }
    }
    FOR(i, 1, n) cout << child[i] << " ";
    cout << cnt << "\n";
    FOR(i, 1, cnt){
        for(auto e:v[i]) cout << e << " ";
        cout << "\n";
    }
    return 0;
}