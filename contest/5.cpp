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
int n, a[MM], m[MM], freq[MM]; int len, ans, mx;

int main(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    for(int i=1;i<=n;i++){
        // memset(freq, 0, sizeof freq);
        memset(m, 0, sizeof m);
        mx = 0;
        for(int j=i;j<=n;j++){
            len = j-i+1;
            // freq[m[a[j]]]--;
            m[a[j]]++;
            // freq[m[a[j]]]++;
            mx = max(mx, m[a[j]]);
            if(mx>len/2){ ans++; }
            // cout << i << " " << j << " " << mx << "\n";
            
        }
    }
    cout << ans << "\n";
    return 0;
}