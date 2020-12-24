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
const ll MM = 102;
ll n, a[MM]; ll sum; ll num, cnt;bool inf;
bool check(ll k){
    if(cnt>1000||k>1e12){
        cout << "INFINITY\n";
        inf = 1;
        return false;
    }
    ll lim = sqrt(k*1.0);
    for(ll i=2;i<=lim;i++){
        if(k%i==0) return true;
    }
    return false;
}
void fun(ll k){
    ll lim = sqrt(k*1.0);
    sum = 1;
    for(ll i=2;i<=lim;i++){
        if(k%i==0){
            sum += i;
            if(k/i!=i) sum += k/i;
        }
    }
    num = sum;
    cnt++;

}
int main(){
    cin >> n;
    FOR(i, 1, n){
        sum = 0; cnt = 0; inf = 0;
        cin >> num;
        while(check(num)){
            fun(num);
            // cout << num << "\n";
        }
        if(!inf){
            cout << num << " " << cnt << "\n";
        }
    }
    return 0;
}