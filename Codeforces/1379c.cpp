
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
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
const int MM = 1e5+2;
pi p[MM];
int ans[MM];
deque<pair<int, pi>> a;
void solve(){
    ll ans = 0;
    int cnt=0;
    int n, m; cin >> n >> m;
    for(int i=1, x, y;i<=m;i++){
        cin >> x >> y;
        p[i].f = x; p[i].s = y;
        a.pb({x, {0, i}});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i=0;i<a.size();i++){
        printf("%d %d %d\n", a[i].f, a[i].s.f, a[i].s.s);
    }
    while(cnt<n){
        if(a.front().s.f==0){
            ans += a.front().f;
            cnt++;
            a.pb({p[a.front().s.s].s, {1, a.front().s.s}});
            a.pop_front();
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
        }
        else{
            ans += a.front().f*(n-cnt);
            cout << ans << "\n";
            return;
        }
    }
    cout << ans << "\n";





}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}