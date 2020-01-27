#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;
int l[20005], r[20005];
int dp[20005][2];
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> l[i] >> r[i];
    }
    dp[1][0] = r[1] - 1 + r[1] - l[1];
    dp[1][1] = r[1] - 1;
    for(int i=2;i<=N;i++){
        dp[i][0] = min(dp[i-1][0] + abs(r[i]-l[i-1]), dp[i-1][1] + abs(r[i]-r[i-1]))+r[i]-l[i];
        dp[i][1] = min(dp[i-1][0]+abs(l[i]-l[i-1]), dp[i-1][1]+abs(l[i]-r[i-1])) + r[i]-l[i];
    }
    int ans = min(dp[N][0]+N-l[N],dp[N][1]+N-r[N])+N-1;
    cout << ans << endl;
    return 0;




}