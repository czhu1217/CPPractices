//wet mud
//priority queue and vector
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
int n, m, j, ans=-1; bool done=0;
pi a[MM];
deque<pi> v;
priority_queue<pi, vector<pi>, greater<pi>> q;
bool comp(pi a, pi b){
    return a.s<b.s;
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> j;
    FOR(i, 1, m) cin >> a[i].f >> a[i].s;
    sort(a+1, a+1+m, comp);
    v.pb({0, 0});
    if(j>n){
        cout << 0 << "\n";
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(a[i].f<=v.back().f) continue;
        if(v.back().f+j>=a[i].f){
            v.pb(a[i]); ans = max(ans, a[i].s);
            while((!q.empty())&&q.top().f<=v.back().f+j){
                v.pb(q.top()); q.pop();
            }
        }
        else q.push(a[i]);
        if(v.back().f+j>n){
            done=1;
            break;
        } 
    }
    if(!done) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;   
}