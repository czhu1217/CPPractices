//intereting knapsack dp
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
const int MM = 305;
int n, m, k, a[MM], b[MM], dp[MM][MM*MM], sumA=0, ans=INT_MAX, sumB=0;
int main(){
    memset(dp, -0x3f, sizeof dp);
    for(int i=0;i<MM;i++){
        dp[i][0] = 0;
    }
    cin >> n >> m >> k;
    FOR(i, 1, n){
        cin >> a[i];
        sumA += a[i];
        if(a[i]<k) return 0*printf("Impossible\n");
    }
    FOR(i, 1, m){
        cin >> b[i];
        sumB += b[i];
        for(int j=0;j<=sumB;j++){
            if(j<b[i]){
                dp[i][j] = dp[i-1][j]; continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]]+min(n, b[i]));
        }
    } 

    for(int i=sumA;i<=sumB;i++){
        if(dp[m][i]>=n*k){
            cout << i - sumA << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";
    return 0;
}