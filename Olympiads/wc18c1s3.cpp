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
const int MM = 2e6+5;
int h, j, n, a, b, ar[MM], cur, pre, cnt=INT_MAX, br[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    memset(ar, 0x3f, sizeof ar);
    cin >> h >> j >> n;
    FOR(i, 1, n){
        cin >> a >> b;
        FOR(j, a, b) br[j] = 1;
    }
    ar[0] = 0;
    for(int i=0;i<h;i++){
        if(br[i]) continue;
        if(!br[i+j]){
            ar[i+j] = min(ar[i+j], ar[i]+1);
            for(int k=i+j-1;k>(ar[i+j]<ar[pre]?i:pre);k--){
                ar[k] = min(ar[k], ar[i+j]+1);
            }
            pre = i+j;
        } 
    }
    for(int i=h;i<h+j;i++){
        cnt = min(cnt, ar[i]);
    }
    if(cnt<=h) cout << cnt << "\n";
    else cout << -1<< "\n";

    return 0;
}