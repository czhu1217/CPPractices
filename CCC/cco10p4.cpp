//knapsack with categories. 
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
#define f first
#define s second
const int MM=6, MM2 = 3005;
int t, dp[MM][MM2], n, b;
vector<pair<int, int>> a[MM];
int main(){
    memset(dp, -1, sizeof dp);
    cin >> t;
    cin >> n;
    for(int i=1, ci, vi, ti;i<=n;i++){
        cin >> ci >> vi >> ti;
        a[ti].push_back({ci, vi});
    }
    cin >> b;
    dp[0][0] = 0;
    for(int i=1;i<=t;i++){
        for(int k=0;k<a[i].size();k++){
            int c = a[i][k].f, v = a[i][k].s;
            for(int j=c;j<=b;j++){
                if(dp[i-1][j-c]>=0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-c]+v);
                }
            }
        }
    }
    ll ans=-1;
    for(int i=1;i<=b;i++){
        if(dp[t][i]>ans){
            ans = dp[t][i];
        }
    }

    cout << ans << "\n";
    return 0;


}