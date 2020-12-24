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
int n, a[MM];ll psa[MM];
int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i]; ll sum1, sum2, sum3, mi = INT_MAX, ans1, ans2, fin;
    FOR(i,1, n){
        psa[i] = psa[i-1] + a[i];
    }
    for(int i=1;i<=n-2;i++){
        ans1 = ans2 = -1;
        mi = INT_MAX;
        int lo = i+1, hi = n-1;
        sum1 = psa[i];
        // cout << i << "\n";
        while(lo!=hi){
            // cout << lo << " " << hi << "\n";
            int mid = (lo+hi)/2;
            sum2 = psa[mid] - sum1;
            sum3 = psa[n] - psa[mid];
            if(ans1<0) ans1 = sum2;
            if(ans2<0) ans2 = sum3;
            if(abs(sum2-sum3)<mi){
                mi = abs(sum2-sum3);
                ans1 = sum2, ans2 = sum3;
            }
            if(sum2>sum3){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        sum2 = psa[lo] - sum1;
        sum3 = psa[n] - psa[lo];
            if(ans1<0) ans1 = sum2;
            if(ans2<0) ans2 = sum3;
        if(abs(sum2-sum3)<mi){
            mi = abs(sum2-sum3);
            ans1 = sum2, ans2 = sum3;
        }
        // cout << sum1 << " " << ans1 << " " << ans2 << "\n";
        fin = min(fin, max(sum1, max(ans1, ans2)) - min(sum1, min(ans1, ans2)));
        // cout << fin << " ok\n";
            
        
    }
    cout << fin << "\n";

    return 0;
}