//run for cheese
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
const int MM = 2005;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
int n, l, a[MM]; ll dp[MM][MM][3];

    memset(dp, 0x3f, sizeof dp);
    cin >> n >> l;

    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1, a+n+1);

    for(int i=1;i<=n;i++) dp[i][i][0] = dp[i][i][1] = n*abs(l-a[i]);
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            dp[i][j][0] = min(dp[i+1][j][0]+(n-len+1)*(a[i+1]-a[i]), dp[i+1][j][1]+(n-len+1)*(a[j]-a[i]));

            dp[i][j][1] = min(dp[i][j-1][0]+(n-len+1)*(a[j]-a[i]), dp[i][j-1][1]+(n-len+1)*(a[j]-a[j-1]));
        }
    }
    ll ans = min(dp[1][n][0], dp[1][n][1]);
    cout << ans << "\n";
    return 0;
}