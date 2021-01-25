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
const int MM = 2e5+5;
int n, a[MM], tmp, id, mi, mx; int no[MM], cr[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        if(a[i]>i){
            cout << -1 << "\n";
            return 0;
        }
        tmp = a[i];id = i;
        tmp--;
        if(tmp>0){no[i-tmp+1]++; no[i+1]--;}
        id -= tmp;
        if(a[i])cr[id] = 1;
    }
    FOR(i, 2, n){ 
        no[i] += no[i-1]; 
        if(no[i]&&cr[i]){
            cout << -1 << "\n";
            return 0;
        }
    }
    FOR(i, 2, n){
        if(!no[i]) mx++;
        if(cr[i]){mi++;}
    }
    cout << mi << " " << mx << "\n";
    return 0;
}