//greedy
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
const int MM = 1e5+5;
int n, m;
struct ev{
    int lett, fre, idx;
    bool operator<(const ev &x){
        return idx < x.idx;
    }
} a[MM];
struct ee{
    int l, r, lt, fr;

};
char ans[MM];
int mx[27];
pi last[27];
deque<ee> dq;
bool ok;
bool comp(ee a, ee b){
    return a.l < b.l;
}
int main(){
    auto compare = [](const ee &lhs, const ee &rhs)
                {
                    bool t = lhs.r != rhs.r ? lhs.r > rhs.r : lhs.fr > rhs.fr;
                    return t;
                };
    memset(last, 0, sizeof last);
    char x; int y, z;
    cin >> n >> m;
    FOR(i, 1, m) {
        cin >> x >> y >> z;
        x -= 'a';
        a[i] = {x, y, z};
        mx[x] = max(mx[x], z);
    }
    sort(a+1, a+1+m);
    FOR(i, 1, m){
        ee tmp;
        tmp.l = last[a[i].lett].f+1;
        tmp.r = a[i].idx;
        tmp.lt = a[i].lett;
        tmp.fr = a[i].fre -last[a[i].lett].s;
        if(tmp.fr<0||(tmp.l>tmp.r&&tmp.fr!=0)) return 0 * puts("-1");
        //duplicate
        if(tmp.l>tmp.r&&tmp.fr==0) continue;
        dq.push_back(tmp);
        last[a[i].lett].f = tmp.r;
        last[a[i].lett].s += tmp.fr;
    }
    sort(dq.begin(), dq.end(), comp);
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    ee t;
    FOR(i, 1, n){
        while((!dq.empty())&&dq.front().l<=i){
            t = dq.front(); dq.pop_front();
            pq.push({t.r, {t.lt, t.fr}});
        }
        while((!pq.empty())&&pq.top().s.s==0) pq.pop();
        if(pq.empty()){
            ok = 0;
            for(int j=0; j<=25;j++){
                if(mx[j]<i){
                    ans[i] = 'a'+j;
                    ok = 1; break;
                }
            }
            if(!ok) return 0 * puts("-1");
            else continue;
        }
        if((!pq.empty())&&pq.top().f < i) return 0 * puts("-1");
        ans[i] = 'a' + pq.top().s.f;
        pair<int, pi> tm = pq.top(); 
        pq.pop();
        tm.s.s--; 
        pq.push(tm);
        while((!pq.empty())&&pq.top().s.s==0) pq.pop();
    }
    FOR(i, 1, n) cout << ans[i];
    cout << "\n";
    return 0;
}