#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
ll n, ans;
const ll mod = 1e9+7;
// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y);
 
// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);

        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
}
 
// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
int main(){
    cin >> n;
    ll pre = n, cur;
    FOR(i, 2, sqrt(n)){
        cur = n/i;
        ll a = (pre+cur+1), b = (pre-cur);
        if(a%2==0) a /= 2; else b/=2;
        a %= mod; b%= mod;
        ans += (((a*b)%mod*(i-1)%mod)%mod);
        ans %= mod;
        pre = cur;
 
    }
    for(ll i=pre;i>0;i--){
        ans += i%mod*(n/i)%mod;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}