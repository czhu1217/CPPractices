
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
#define f first
#define s second
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
void solve(){
    int n, m; cin >> n >> m;
    int a[1002], b[1002];bool vis[1002];
    memset(vis, 0, sizeof vis);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        vis[a[i]] = 1;
    }
    bool pos = 0;
    for(int i=1;i<=m;i++){
        cin >> b[i];
        if(vis[b[i]]&&!pos){
            cout << "YES\n";
            cout << 1 << " "  << b[i] << "\n";
            pos = 1;
        }
    }
    if(!pos)cout << "NO\n";

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}