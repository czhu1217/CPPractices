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
const int MM = 3e6+5;
ll n, a[MM], k, ans; 
deque<pi> mi, mx;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    FOR(i, 1, n){
        cin >> a[i];
    } 
    int l=1, r=1; 
    mi.push_back({a[1], 1}); mx.push_back({a[1], 1});
    while(r<=n){
        if(mx.front().f-mi.front().f<=k){
            ans += r-l+1;
            r++;
            while((!mx.empty())&&mx.back().f<a[r]) mx.pop_back();
            mx.pb({a[r], r});
            while((!mi.empty())&&mi.back().f>a[r]) mi.pop_back();
            mi.pb({a[r], r});
        }
        else{
            while((!mx.empty())&&(!mi.empty())&&mx.front().f-mi.front().f>k){
                if(mx.front().s<mi.front().s){
                    l = mx.front().s+1;
                    mx.pop_front();
                }
                else if(mx.front().s>mi.front().s){
                    l = mi.front().s+1;
                    mi.pop_front();
                }
                else{
                    l = mi.front().s+1;
                    mi.pop_front(); mx.pop_front();
                }
            }            
        }
    }

    cout << ans << "\n";
    return 0;
}