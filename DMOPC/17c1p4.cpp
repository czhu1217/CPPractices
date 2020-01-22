#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int N,H;
ll dp[2][5002];
int main(){
    cin >> N >> H;
    for(int i=1, pre = 0, cur = 1, g, h, q, t;i<=N;i++){
        cin >> g >> h >>q >>t;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for(int j=h;j<=H;j++){
            dp[cur][j]  = dp[pre][j-h] + g; 

        }
        for(int j=h+t; j<=H;j++){
            dp[cur][j] = max(dp[cur][j], dp[cur][j-t]+q);

        }
        for(int j=1;j<=H;j++){
            dp[cur][j] = max(dp[cur][j], dp[pre][j]);
        }
        swap(cur, pre);

    }
    printf("%lld\n", dp[N%2][H]);
    return 0;
}