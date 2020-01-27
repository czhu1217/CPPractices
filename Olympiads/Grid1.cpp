#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int H, W;
bool map[1003][1003];
const long long mod = 1e9+7;
long long dp[1003][1003];
int main(){
    cin >> H >> W;
    memset(dp, 0, sizeof(dp));
    memset(map, false, sizeof(map));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            char c;
            cin >> c;
            if(c=='.') map[i][j] = true;
        }
    }
 
    dp[1][1] = 1;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(map[i][j]){
                dp[i][j] += dp[i-1][j]%mod;
               dp[i][j] += dp[i][j-1]%mod; 
            //    cout << dp[i][j] << "\n";
            }
        }
    }
    

    cout << dp[H][W]%mod << "\n";
    return 0;
}