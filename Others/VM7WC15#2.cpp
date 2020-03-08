#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
int n; string s;
int dp[100][25005];
int ans=0;
int main(){
    cin >> n >> s;
    for(int i=0; i<n;i++){
        dp[i][i] =  1;
    }
    int cur = 1, pre = 0;
    for(int i=1; i<=n;i++){
        for(int j=0;j<n-i;j++){
            int r = j+i;
            // cout << j << " " << r << endl;
            if(s[j]==s[r]&&i==1){
                dp[j][r] = 2;
            }
            else if(s[j]==s[r]){
                dp[j][r] = dp[j+1][r-1]+2;
                if(dp[j][r]>ans)ans = dp[j][r];

            }
        }
    }
    cout << ans << endl;
    return 0;
}