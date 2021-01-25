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
const int MM = 1e6+5;
ll n, x; bool in[MM];
int main(){
    cin >> n >> x;
    if(x>((1+n-2)*(n-2)/2)){
        cout << -1 << "\n";
        return 0;
    }
    for(int i=n-2;i>0;i--){
        if(x>=i){
            in[n-1-i] = 1;
            x -= i;
        }
    }
    FOR(i, 1, n-2){
        if(!in[i]) cout << i << " ";
    }
    cout << n-1 << " ";
    FOR(i, 1, n-2){
        if(in[i]) cout << i << " ";
    }
    cout << n << "\n";

    return 0;
}