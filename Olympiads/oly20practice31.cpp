#include <iostream>
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
using namespace std;
int N, M, R;
const int MM = 1e6, MM2 = 1e3;
struct task{
    int s, e, v;
    bool operator<(const task &a){
        return e<a.e;
    }
}; vector<task> op;
int dp[MM+2];

int main(){
    cin >> N >> M >> R;
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        op.push_back({a, b, c});
    }
    sort(op.begin(), op.end());
    for(auto a:op){
        int e = a.e, s = a.s, v = a.v;
        dp[e] = max(dp[e], dp[max(s-R, 0)]+v);
        for(int i=e;i<=N;i++){
            dp[i] = max(dp[i], dp[e]);
        }
    }
    cout << dp[N] << "\n";
    return 0;
}