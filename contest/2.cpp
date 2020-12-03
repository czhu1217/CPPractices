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
ll n;
ll tot[22], sum[22], ans;
int dig(ll n){
    int cnt = 0;
    while(n){
        cnt++;
        n = n/10;
    }
    return cnt;
}
ll quick_pow(ll x, int exp){
    if(exp==0)return 1;
    ll t = quick_pow(x, exp/2);
    t = t*t;
    return (exp&1)?t*x:t;
}
int main(){
    for(int i=1;i<=21;i++){
        tot[i] = quick_pow(10, i) - quick_pow(10, i-1);
    }
    sum[1] = tot[1];
    for(int i=3; i<=21;i+=2){
        sum[i] = tot[i] + sum[i-2];
    }
    cin >> n;
    int a = dig(n);
    if(a%2==0) cout << sum[a-1] << "\n";
    else{
        if(a-2) ans += sum[a-2];
        ans += n-quick_pow(10, a-1)+1;
        cout << ans << "\n";
    }

  
    return 0;
}
