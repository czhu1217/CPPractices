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
int n, a[200005];
int main(){
    bool dec = 0;
    bool ans = 1;
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }
    FOR(i, 2, n){
        if(dec&&a[i]>a[i-1]){
            ans = 0;
            break;
        }
        if(a[i]<a[i-1]){
            dec = 1;

        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}