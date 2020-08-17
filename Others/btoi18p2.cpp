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
int n, k, r, a[MM];
int m[MM], req[MM];
int cnt=0, ans=INT_MAX;
int main(){
    cin >> n >> k >> r;
    FOR(i, 1, n){
        cin >> a[i];
    }
    int l=1;
    FOR(i, 1, r){
        int x, y; cin >> x >> y;
        req[x]=y;
    }
    cnt=r;
    for(int r=1;r<=n;r++){
        m[a[r]]++;
        if(m[a[r]]==req[a[r]]) cnt--;
        while(cnt==0){
            if(m[a[l]]>req[a[l]]){
                m[a[l]]--;
                l++;
            }
            else break;
        }
        if(cnt==0) ans = min(ans,  r-l+1);

    }
    if(ans!=INT_MAX)
    cout << ans << "\n";
    else cout << "impossible" << "\n";
    return 0;
}