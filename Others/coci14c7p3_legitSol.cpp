#include <bits/stdc++.h>
using namespace std;
int N, a[3][150002], dp[3][150002], b[3]={0, 1, 2}, INF = 0x3f3f3f3f, ans=INF;
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N);
    for(int i=0; i<3; i++)
        for(int j=1; j<=N; j++)
            scanf("%d", &a[i][j]);
    do{
        memset(dp, 0x3f, sizeof(dp));
        dp[2][N] = a[b[2]][N];
        for(int k=2; k>=0; k--)
            for(int i=N-1; i>=1; i--)
                if(k==2) dp[k][i]=dp[k][i+1]+a[b[k]][i];
                else dp[k][i]=min(dp[k+1][i+1]+a[b[k]][i], dp[k][i+1]+a[b[k]][i]);
        ans = min(ans, dp[0][1]);
    }while(next_permutation(b, b+3));
    printf("%d\n", ans);
}