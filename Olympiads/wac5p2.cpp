
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
const int MM = 200005;
int n, q, a[MM], cnt;
pi p[MM];
int ai, bi, hi, lo, mid;
int main(){
    cin >> n >> q;
    p[0].f = INT_MAX;
    p[0].s = INT_MIN;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        // p[i].f = min(a[i], p[i-1].f);
        // p[i].s = max(a[i], p[i-1].s);

    }
    for(int i=n;i>0;i--){
        p[n-i+1].f = min(a[i], p[n-i].f);
        p[n-i+1].s = max(a[i], p[n-i].s);

    }
    // for(int i=1;i<=n;i++){
    //     cout << p[i].f << " " << p[i].s << "\n";
    // }
    for(int i=1, x, y;i<=q;i++){
        cin >> x >> y; 
        lo = 0; hi = n;
        while(hi-lo>1){
            mid = (lo+hi)/2;
            if(x+y>=p[mid].s&&x-y<=p[mid].f){
                lo = mid;
            }
            else hi = mid-1;
        }
        if(x+y>=p[hi].s&&x-y<=p[hi].f) cout << hi << "\n";
        else cout << lo << "\n";
        
    }

    return 0;
}