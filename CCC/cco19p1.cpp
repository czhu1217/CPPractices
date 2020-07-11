#include <bits/stdc++.h>
#define f first
#define s second
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 15, MX = 20000000;
// 0 is J's turn, 1 is D's turn
// 0 empty, 1 J, 2 D
int r, c; char ch[MM][MM]; double dp[MX][2]; vector<vi> a;
int lmt[2];
vpi op{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vi tri(int msk){
    vi a(r*c);
    for(int i=0;i<r*c;i++){
        a[i] = msk%3; msk /=3;
    }
    reverse(a.begin(), a.end());
    return a;
}
int dec(vi tri){
    int res = 0;
    for(auto e:tri){
        res = res*3+e;
    }
    return res;
}
bool check(int i, int j){
    if(i>=r||j>=c||i<0||j<0) return false;
    return true;
}
double solve(ll mask, ll turn){
    if(dp[mask][turn]>=0) return dp[mask][turn];
    double &ans = dp[mask][turn];
    vi ar = tri(mask);
    int grid[MM][MM];
    int it = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            grid[i][j] = ar[it++];
        }
    }
    vector<double> choices;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]-1!=turn)continue;
            int x, y;
            for(auto e:op){
                x = i+e.f, y = j+e.s;
            if(check(x, y)&&grid[x][y]){
                int temp = grid[x][y];
                grid[x][y] = grid[i][j];
                grid[i][j] = 0;
                vi nxt;
                for(int m=0;m<r;m++){
                    for(int n=0;n<c;n++){
                        nxt.pb(grid[m][n]);
                    }
                }
                grid[i][j] = grid[x][y]; grid[x][y] = temp;
                choices.pb(1-solve(dec(nxt), !turn));
            }
            }
            
        }
    }
    sort(choices.begin(), choices.end()); reverse(choices.begin(), choices.end());
    int t = choices.size();
    int sz = min(lmt[turn], t);
    ans=0;
    for(int i=0;i<sz;i++){
        ans += choices[i];
    }
    if(sz>0) ans /= sz;
    return ans;
}
int main(){
    memset(dp, -1, sizeof dp);
    cin >> r >> c;
    vi arr(r*c);
    for(int i=0;i<r*c;i++){
        char ca; cin >> ca;
        if(ca=='J') arr[i] = 1;
        else arr[i] = 2;
    }
    cin >> lmt[0] >> lmt[1];
    printf("%.3f\n", solve(dec(arr), 0))   ; 
    return 0;
}