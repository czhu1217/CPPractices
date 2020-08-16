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
const int MM = 5005;
int dp[MM][MM][3];
string s; char a[5005];
int n;
int calc(int idx, int t){
    if(a[idx]=='('&&t!=1) return 1;
    if(a[idx]==')'&&t==1) return 1;
    return 0;
}
bool fun(int idx, int lft, int t){
    int &res = dp[idx][lft][t];
    if(dp[idx][lft][t]>=0)return dp[idx][lft][t];
    res = 0;
    int rit = idx-lft-1;
    if(idx==n+1 && rit==lft) return 1;
    if(idx==n+1&&rit!=lft) return 0;
    if(rit>lft) return 0;

    if(t==0){
        if(fun(idx, lft, 1)) res= 1;
    }
    else if(t==1){
        if(fun(idx, lft, 2)) res = 1;
    }
    if(fun(idx+1, lft+calc(idx, t), t)) res =  1;
    return res;

    
}
int main(){
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    for(int i=0;i<n;i++){
        a[i+1] = s[i];
    }
    int pos = fun(1, 0, 0);
    if(pos) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}