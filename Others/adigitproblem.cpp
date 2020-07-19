
//digit dp
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
const int mod = 1e9+7;
int n, expect; int dp[1002][1<<10][2][2];
string s;
int fun(int pos, int mask, bool lim, bool zero ){
    int &ans = dp[pos][mask][lim][zero];
    if(ans>=0)return ans;
    if(pos==s.length()){
        return ans = (mask&expect)==expect;
    }
    int val = s[pos]-'0';
    int bound = lim ? val:9;
    ans = 0;
    for(int i=0;i<=bound;i++){
        ans += fun(pos+1, (zero&&i==0)?mask:mask|1<<i, lim&&i==val,zero&&i==0);
        ans %= mod;
    }
    return ans;


}
int main(){
    memset(dp, -1, sizeof dp);
    cin >> n; 
    for(int i=1, x;i<=n;i++){
        cin >> x; expect |= 1<<x;
    }
    cin >> s;

    cout << fun(0, 0, 1, 1) + (expect==1) << "\n";
    return 0;
}