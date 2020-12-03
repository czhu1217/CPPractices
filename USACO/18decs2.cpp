//priority queue
//AC
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
pair<int, pair<int, int>> cow[MM];
int n, ans;
priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> v;
bool cmp(pair<int, pi> a, pair<int, pi> b){
    return a.s.f < b.s.f;
}

int main(){

    freopen("convention2.in", "r", stdin);    freopen("convention2.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n){
        scanf("%d %d", &cow[i].s.f, &cow[i].s.s);
        cow[i].f = i;
    }
    sort(cow+1, cow+1+n, cmp);
    v.push(cow[1]); int it = 2; int cur = cow[1].s.f;
    while(!v.empty()){
        pair<int, pi> a = v.top();
        v.pop();
        ans = max(ans, cur-a.s.f);
        cur += a.s.s;
        while(it<=n){
            if(cow[it].s.f<=cur){
                v.push(cow[it]);
                it++;
            }
            else break;
        }
        if(v.empty()&&it<=n){
            v.push(cow[it]);
            cur = cow[it].s.f;
            it++;
        } 
    }
    printf("%d\n", ans);
    return 0;
}