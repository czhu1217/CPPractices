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
using namespace std;
typedef long long ll;
const int MM = 1505;
int a[MM][MM], dp[MM][MM];
int n;int ans=0;
int dfs(int r, int c,  int prev ){
    int cur = a[r][c];

    if(r<1||c<1||r>n||c>n)return 0;
    if(a[r][c]<prev||a[r][c]==prev)return 0;
    if(dp[r][c])return dp[r][c];
    dp[r][c] = max(dfs(r, c-1, cur), max(dfs(r, c+1,  cur), max(dfs(r-1, c, cur),dfs(r+1, c,cur))))+1;
    return dp[r][c];
}
void solve(){
    memset(dp, 0, sizeof dp);
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d", &a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!dp[i][j]) dfs(i, j, INT_MIN);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans-1 << "\n";
}

int main(){
    solve();
    return 0;
}