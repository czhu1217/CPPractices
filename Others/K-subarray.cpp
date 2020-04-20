#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;
const int MM = 2e4+2;
int N, K, psa[MM], dp[2][MM], mx[2][MM], pre=0, cur=1;
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    memset(dp, -0x3f, sizeof dp);
    memset(mx, -0x3f, sizeof mx);
    dp[0][0]=0;mx[0][0]=0;
    for(int i=1;i<=N;i++){
        dp[cur][0] = 0;
        for(int k=1;k<=K;k++){
            dp[cur][k] = max(dp[pre][k], mx[pre][k-1]+psa[i]);
        }
        for(int k=0;k<=K;k++){
            mx[cur][k] = max(mx[pre][k], dp[cur][k]-psa[i]);
        }
        swap(pre, cur);
    }
    cout << dp[pre][K] <<  endl;
    return 0;

}