
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
int n, d, m;
const int MM = 1e5+5;
int a[MM], psa1[MM], psa2[MM];
vector<int> v, g;
int main(){
    ll sum=0, ans=0;
    cin >> n >> d >> m;
    for(int i=1, x;i<=n;i++){
        cin >> x;
        if(x>m)v.pb(x);
        else g.pb(x);
    }
    sort(all(v));
    reverse(all(v));
    sort(all(g));
    // for(auto e:v) cout << e << " ";
    // cout << "\n";
    // for(auto e:g) cout << e << " ";
    for(int i=1;i<=v.size();i++){
        psa1[i] = psa1[i-1]+v[i-1];
    }
    for(int i=1;i<=g.size();i++){
        psa2[i] = psa2[i-1]+g[i-1];
    }
    for(int i=0;i<=v.size();i++){
        ll res=0;
        res += psa1[(int)ceil((int)v.size()/d)+i];
        res += psa2[g.size()];
        res -= psa2[d*i];
        if(res>ans)ans=res;
        
    }
    cout << ans << "\n";



    return 0;
}