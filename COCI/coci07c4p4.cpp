//2 partitioning
//minimize difference of sums
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
typedef pair<int, int> pi;
const int MM = 505, MMT = 5005;
int t, n, a[505]; bool dp[MM][MMT*2];
bool in[MM];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t >> n; ll sum=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int j=1;j<=sum;j++)
        dp[0][j] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=sum;j++){
            if(a[i]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
        }
    }
int ed;
    for(int i=(sum+1)/2; i>0;i--){
        if(dp[n][i]){
            ed = i; break;
        }
    }
    int it=n;
    memset(in, 0, sizeof in);
    for(int i=ed;i>0;){
        if(dp[it][i]&&!dp[it-1][i]){
            in[it]=1;
            i -= a[it];
        }
        it--;
    }
    ll tsum=0, tsum2=0;
    for(int i=1;i<=n;i++){
        if(in[i]){
            cout << tsum << " ";
            tsum += a[i];
        }
        else{
            cout << tsum2 << " ";
            tsum2 += a[i];
        }
    }
    cout << "\n";
    return 0;
    



}