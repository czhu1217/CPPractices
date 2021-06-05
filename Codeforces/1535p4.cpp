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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = (1<<19)+5;
int k, q, p, n; char a[MM]; string s; int pos[MM];
char c;
void fun(int x){
    if(x>n){
        pos[x] = 1; return;
    }
    fun(2*x); fun(2*x+1);
    if(a[x]=='0'){
        pos[x] = pos[2*x+1];
    }
    else if(a[x]=='1'){
        pos[x] = pos[2*x];
    }
    else{
        pos[x] = pos[2*x] + pos[2*x+1];
    }
}
void update(int x){
    if(!x) return;
    if(a[x]=='0'){
        pos[x] = pos[2*x+1];
    }
    else if(a[x]=='1'){
        pos[x] = pos[2*x];
    }
    else{
        pos[x] = pos[2*x] + pos[2*x+1];
    }
    update(x/2);

}
int main(){
    cin >> k;
     n = pow(2, k)-1;
    FOR(i,1, n) cin >> a[n+1-i];
    fun(1);
    cin >> q;
    while(q--){
        cin >> p >> c;
        p = n+1-p;
        a[p] = c;
        update(p);
        cout << pos[1] << "\n";

    }

 

    return 0;
}