
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#include <stack>
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
int n, m;
const int MM = 203;

int a[MM], b[MM], c[MM];
bool ab[MM][12], bb[MM][12];
vector<int> choices[MM];
void solve(){
    memset(c, 0x3f, sizeof c);
    cin >> n >> m;
    FOR(i, 1, n)cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    ll ans=0;
    bool pos = 1, pos2=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) choices[i].pb(b[j]);
    }

    for(int i=9;i>=0;i--){
        pos = 1;
        vector<int> v[MM];
        for(int j=1;j<=n;j++){
            // for(auto e:choices[j]) cout << e << " ";
            // cout << "\n";
                     
            for(auto &e:choices[j]){
                int tmp = a[j]&e;
                if((tmp&(1<<i))==0){
                     v[j].pb(e);
                }
                
            }
            if(v[j].empty()){
                pos = 0; break;
            }

        }
        if(!pos){
            ans += (1<<i);
            // cout << i << "\n";

        } 
        else{
            swap(v, choices);
        }
        // cout << "\n";
    }
    cout << ans << "\n";


}
int main(){
    solve();
    return 0;
}