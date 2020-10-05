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
int ans;
void solve(){
    int a, b; char c;
    cin >> a >> c >> b;
    if(a<=1&&b<=2){
        ans = 2-b+1 + 2 + 4;
    }
    else if(a<4||(a==4&&b<=2)){
        if(a==4){
            ans = 4+2-b+1;
        }else{
            ans = 12 - ((a-1)*4+b) +1 + 2 + 4;
        }
    }
    else{
        ans = (8-a)*4+4-b+1;
    }
    cout << ans << "\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}