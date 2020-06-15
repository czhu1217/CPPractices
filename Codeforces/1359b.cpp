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
void solve(){
    bool a[1002][1002]; int dp[1002];
    int n, m, x, y;

    cin >> n >> m >> x >> y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            if(c=='*') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    ll ans=0;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!a[i][j]){ dp[j] = dp[j-1]; continue;}
            if(!a[i][j-1]){ dp[j] = dp[j-1]+x; continue;}
            dp[j] = min(dp[j-1]+x, dp[j-2]+y);
        }
        ans += dp[m];
    }
    cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}