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
const int MM = 2e5+5;
int n, w[MM], ind[MM];
void solve(){
    vector<pi> v;
    cin >> n; ll sum=0, cnt=0;
    FOR(i, 1, n){ cin >> w[i]; sum += w[i];}
    FOR(i, 1, n) ind[i]=0;
    int x, y;
    FOR(i, 1, n-1){
        cin >> x >> y;
        ind[x]++;
        ind[y]++;
    }
    FOR(i, 1, n){
        v.pb({w[i], ind[i]});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << sum << " ";
    cnt++;
    for(int i=0;i<v.size();i++){
        for(int j=1;j<=v[i].s-1;j++){
            if(cnt>=n-1){
                break;
            }
            sum += v[i].f;
            cout << sum << " ";
            cnt++;
        }
    }
    for(int i=cnt;i<n-1;i++) cout << sum << " ";
    cout << "\n";
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}