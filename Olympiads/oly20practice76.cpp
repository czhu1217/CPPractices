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
const int MM = 1e5+5;
int n, psa[MM], psa2[MM], ans; string a;
bool vis[MM][30], vis2[MM][30];
int main(){
    memset(vis, 0, sizeof vis);
    memset(vis2, 0, sizeof vis2);
    cin >> n >> a;
    for(int i=0;i<n;i++){
        FOR(j, 0, 25) vis[i][j] = vis[i-1][j];
        vis[i][a[i]-'a'] = 1;

    }
    for(int i=n-1;i>=0;i--){
        FOR(j, 0, 25) vis2[i][j] = vis2[i+1][j];
        vis2[i][a[i]-'a'] = 1;

    }
    for(int i=0;i<n;i++){
        int cnt = 0;
        FOR(j, 0, 25){
            if(vis[i][j]&&vis2[i][j]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}