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
const int MM = 25, mh = 50;
int n, m, a[MM][MM], ans=0;
    bool l, r, up, down;

int solve(){
    ans = 0;
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> a[i][j];
        }
    }
    FOR(i, 1, n){
        FOR(j, 1, m){
            for(int k=0;k<=50;k++){
                l=r=up=down=0;
                for(int p = 1; p<j;p++){
                    if(a[i][p]-a[i][j]>=k) l = 1;
                }
                for(int p = j+1; p<=m;p++){
                    if(a[i][p]-a[i][j]>=k) r = 1;
                }
                for(int p = 1; p<i;p++){
                    if(a[p][j]-a[i][j]>=k) up = 1;
                }
                for(int p = i+1; p<=n;p++){
                    if(a[p][j]-a[i][j]>=k) down = 1;
                }
                if(l&&r&&up&&down){
                    if(k)
                    ans++;
                }
                else break;
            }
            // cout << " ";
        }
        // cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}
int main(){
    FOR(i,1,5) solve();
    return 0;
}