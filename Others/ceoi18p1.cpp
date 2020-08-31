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
ll n, m;
const int MM = 4001*51;
struct ev{
    ll c, f, v;
    bool operator<(const ev &e){
        return f==e.f?v<e.v:f>e.f;
    }
};
ev a[4005]; ll sum;
ll dp[MM];
ll ans = 0;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].c >> a[i].f >> a[i].v;
        a[i].v = -a[i].v;
    }
    cin >> m;
    for(int i=n+1;i<=m+n;i++){
        cin >> a[i].c >> a[i].f >> a[i].v;
        a[i].c = -a[i].c;
    }
    sort(a+1, a+m+n+1);
    memset(dp, -0x3f, sizeof dp);
    dp[0]=0;
    for(int i=1;i<=m+n;i++){
        if(a[i].v<0){
            //a[i].c>0, iterate from the right
            sum += a[i].c;
            for(int j=sum;j>=a[i].c;j--){
                dp[j] = max(dp[j], dp[j-a[i].c]+a[i].v);
            }
        }
        else{
            //a[i].c<0, iterate from the left
            for(int j=0;j<=sum+a[i].c;j++){
                dp[j] = max(dp[j], dp[j-a[i].c]+a[i].v);
            }
        }
    }
    for(int i=0;i<=sum;i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}