//grouping
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int MM = 17; const int po=131072;
int N, a[MM][MM]; ll sum[po]; ll dp[po];
ll solve(int mask){
    if(!mask)return 0;
    if(dp[mask]>=0)return dp[mask];
    int i=mask;
    dp[mask]=0;
    while(i>0){
        dp[mask] = max(dp[mask], sum[i]+solve(mask^i));
        i = (i-1)&mask;
    }
    return dp[mask];

}
int main(){
    memset(dp, -1, sizeof dp);
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int x=1;x<(1<<N);x++){
        for(int j=1;j<=N;j++){
            if(x&(1<<(j-1))){
                for(int k=1;k<=j;k++){
                    if(x&(1<<(k-1))){
                        sum[x] += a[j][k];
                    }
                }
            }
        }
    }
    ll ans = solve((1<<N)-1);
    cout << ans << "\n";
    return 0;
    

}