#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
long long N=0, a[1002], b[1002], dp[1002][1002];
int main(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> N;
    string t, s;
    cin >> s;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    cin >> t;
    for(int i=1;i<=N;i++){
        cin >> b[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(s[i-1]!=t[j-1]&&((s[i-1]=='W'&&a[i]>b[j])||(s[i-1]=='L'&&a[i]<b[j]))){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[i]+b[j]);
            }
        }
    }
    cout << dp[N][N] << endl;
    return 0;




}