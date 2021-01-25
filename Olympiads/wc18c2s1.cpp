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
int x, y, n, m, c, v, h, chip, mxv = 1e6, miv=0, mxh=1e6, mih=0, cx, cy;
int main(){
    cin >> x >> y >> n >> m >> c;
    FOR(i, 1, n){
        cin >> v;
        if(v<x){
            miv = max(miv, v);
        }
        if(v>x) mxv = min(mxv, v);
    }
    FOR(i, 1, m){
        cin >> h;
        if(h<y) mih = max(mih, h);
        if(h>y) mxh = min(mxh, h);
    }
    FOR(i, 1, c){
        cin >> cx >> cy;
        if(cx<miv||cx>mxv||cy<mih||cy>mxh){
            cout << "N\n";
        }
        else cout << "Y\n";

    }
    return 0;
}