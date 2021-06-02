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
const int MN = 105, MM = 16;
int n, m, k, a[MN][MM], cnt[MM];
int ans, res = INT_MAX;
void fun(int msk){
    int cnt[MM]; int mx = 0;
    memset(cnt, 0, sizeof cnt);
    FOR(i, 1, n){
        FOR(j, 1, m){
            if((msk&(1<<(a[i][j]-1)))!=0){
                cnt[a[i][j]]++;
                break;
            }
        }
    }
    FOR(i, 1, m){
        if(cnt[i]>mx){
            mx = cnt[i];
            ans = i;
        }
    }

}
int count0(int msk){
    int cnt = 0;
    for(int i=0;i<m;i++){
        if((msk&(1<<i))==0){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    cin >> n >> m >> k;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> a[i][j];
            if(j==1) cnt[a[i][j]]++;
        }
    }
    int mx = 0, ans1;
    FOR(i, 1, m){
        if(cnt[i]>mx){
            mx = cnt[i]; ans1 = i;
        }
    }
    cout << ans1 << "\n";
    // cout << res << "\n";
    for(int msk = (1<<m)-1;msk>=0;msk--){
        int mask = msk|(1<<(k-1));
        fun(mask);
        if(ans==k){
            // cout << mask << "\n";
            res = min(res, count0(mask));
        }
    }
    cout << res << "\n";
    return 0;
}