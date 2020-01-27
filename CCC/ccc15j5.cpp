//pi day
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[255][255], n, m, ans=0;
int main(){
    scanf("%d %d", &n, &m);
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        if(i*m<=n){
            dp[1][i*m]++;
        }
        else{
            break;
        }
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d ", dp[1][i]);
    }
    printf("\n");
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j-0){
                
            }

            
        }

    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ", dp[i][j]);
        }
        printf("%d\n");
    }
 
    for(int i=1;i<=n;i++){
        ans += dp[m][i];
    }

    printf("%d", ans);
    return 0;
}