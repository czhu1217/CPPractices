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
int m, n, k;
int a[1505][1505], ans[4]; ll psa[1505][1505];ll sum;
ll query(int i, int j){

}
int main(){
    cin >> m >> n >> k; 
    for(int i=1;i<=m;i++){
        sum=0;
        for(int j=1;j<=n;j++){
            cin >> a[i][j]; sum+=a[i][j];
            psa[i][j] = psa[i-1][j]+sum;
        }
    }
    for(int i=1;i+k<=m;i++){
        for(int j=1;j+k<=n;j++){
            ll tmp = query(i, j);
            if(tmp>b[1]){
                b[1] = tmp;
                sort(b+1, b+4);
            }
        }
    }
    
    return 0;
}