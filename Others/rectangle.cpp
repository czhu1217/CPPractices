//count number of rectangles given coordinates
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
int n;
map<ll, vector<pair<pi, pi>>> m;
vpi v;
const int MM = 1005;
ll ans=0;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b; cin >> a >> b;
        v.pb(mp(a, b));
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1; j<v.size();j++){
            int x1, y1, x2, y2;
            x1 = v[i].f, y1 = v[i].s, x2 = v[j].f, y2 = v[j].s;
            m[pow(x1-x2, 2)+pow(y1-y2, 2)].pb(mp(v[i], v[j]));
        }
    }
    for(auto e:m){
        for(int i=0;i<e.s.size();i++){
            for(int j=i+1;j<e.s.size();j++){
                double c1x, c1y, c2x, c2y;
                c1x = (double)(e.s[i].f.f+e.s[i].s.f)/(double)2;
                c1y = (double)(e.s[i].f.s+e.s[i].s.s)/(double)2;
                c2x = (double)(e.s[j].f.f+e.s[j].s.f)/(double)2;
                c2y = (double)(e.s[j].f.s+e.s[j].s.s)/(double)2;
                if(c1x==c2x&&c1y==c2y){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}