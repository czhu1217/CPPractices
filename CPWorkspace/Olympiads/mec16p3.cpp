//basically knapsack
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, dp[105][105];

int main(){
    cin >> N >> T;
    for(int i=1, L;i<=N;i++){
        cin >> L;; int t = 0, v = 0;
        for(int j=1, x, y;j<=L;j++){
            cin >> x >> y;
            t += x; v+=y;
            for(int k=1;k<=T;k++){
                dp[i][k] = max(dp[i][k], dp[i-1][k]);
                if(k>=t){dp[i][k] = max(dp[i][k], dp[i-1][k-t]+v);}
            }
        }
    }
    cout << dp[N][T] << "\n";
    return 0;



}