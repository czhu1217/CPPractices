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
const int MM = 2005;
    double d;
int n; pi a[MM]; int dpp[MM], dpc[MM], di[MM]; bool f[2*MM];
double dis(int i, int j){
    return ((a[i].f-a[j].f)*(a[i].f-a[j].f)+(a[i].s-a[j].s)*(a[i].s-a[j].s));
}
struct ed{
    int d, x, y;
    bool  operator<(const ed &e){
        return d<e.d;
    }
}; vector<ed> v;
int main(){
    cin >> n;
    FOR(i, 1, n)cin >> a[i].f >> a[i].s;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.pb({dis(i, j), i, j});
        }
    }
    sort(v.begin(), v.end());
    for(auto &e:v){
        int x = e.x, y = e.y, d=e.d;
        if(di[x]!=d){
            di[x] = d;
            dpp[x] = dpc[x];
        }
        if(di[y]!=d){
            di[y] = d;
            dpp[y] = dpc[y];
        }
        if(x!=0){
            dpc[x] = max(dpc[x], dpp[y]+1);
            dpc[y] = max(dpc[y], dpp[x]+1);
        }
        else{
            dpc[x] = max(dpc[x], dpp[y]);
        }
    }
    cout << dpc[0]+1 << "\n";
    return 0;

}