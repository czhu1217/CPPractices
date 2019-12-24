#include <bits/stdc++.h>
using namespace std;
int n, k, st[21][1000005];
long long ans, dp[1000005];
int rmq(int x, int y){
    if(x>y) return 0;
    int k=log2(y-x+1);
    return max(st[k][x], st[k][y-(1<<k)+1]);
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++) scanf("%d", &st[0][i]);
    for(int i=1;i<21;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
    for(int i=1, j=0;i<=n;i++){
        int limit = ((i+k-1)/k-1)*k;
        if(j<i-k) j=i-k;
        while(j<limit&&dp[j]+rmq(j+1, i) <= dp[j+1]+rmq(j+2, i)) j++;
        dp[i] = max(dp[i], dp[j] + rmq(j+1, i));
    }
    printf("%lld\n", dp[n]);
    return 0;
}