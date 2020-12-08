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
const int MM = 1e5+5, MM2 = 1e6+4;
int n, m, first[MM2], last[MM2], a[MM], ai[MM], bi[MM]; int ans = 0;
int main(){
    for(int i=1;i<=MM2;i++){
        first[i] = 1e7; last[i] = -1e7;
    }
    cin >> n >> m;
    FOR(i, 1, n){
        cin >> a[i];
    }
    for(int i=1, a, b; i<=m;i++){
        cin >> ai[i] >> bi[i];
    }
    FOR(i, 1, n){
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    int len=0;
    FOR(i, 1, m){
        if(last[bi[i]]!=-1e7&&first[ai[i]]!=1e7){
        len = last[bi[i]] - first[ai[i]]+1;
        ans = max(ans, len);
        }
    }
    cout << ans << "\n";


    return 0;
}