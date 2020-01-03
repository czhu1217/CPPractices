//3 partitiion
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
bool dp[21][2002][2002];
int a[22];
int sum = 0, N, ans = 100000, temp;
int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    memset(dp[0], false, sizeof(dp[0]));
    dp[0][0][0] = true;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=sum/2;j++){
            for(int k=0;k<=sum/2;k++){
                // printf("%d %d %d %d\n", i, j, k, a[i]);
                dp[i][j][k] = dp[i-1][j][k];
                if(a[i]<=j&&!dp[i][j][k]){
                    dp[i][j][k] = dp[i-1][j-a[i]][k];
                 
                }
                if(a[i]<=k&&!dp[i][j][k]){
                    dp[i][j][k] = dp[i-1][j][k-a[i]];
                   
                }
                // if(dp[i][j][k])printf("%d %d %d %d\n", i, j, k, a[i]);
                
            }
        }
    }
    for(int i=0;i<=sum;i++){
        for(int j=0;j<=sum/2;j++){
            // printf("%d %d\n", i, j);
            if(dp[N][i][j]){
                // printf("hoho %d %d %d\n", i, j, sum-i-j);
                temp = max(sum-i-j, max(i, j)); 
                if(temp<ans)ans = temp;
            }
        }
    }
    printf("%d\n", ans);
    return 0;

}