#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int n; ll c, dp[MM], h[MM];
deque<int> dq;
double slope(int j, int k){
    return (double)(( dp[k] + pow(h[k], 2)) - ( dp[j] + pow(h[j], 2))) /(2.0* (double) (h[k] - h[j])); 
}
int main(){
    cin >> n >> c;
    
    for(int i=1;i<=n;i++){
         cin >> h[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    dq.push_back(1);
    for(int i=2;i<=n;i++){
        while((!dq.empty())&&dq.size()>=2&&slope(dq[0], dq[1])<=h[i]){
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + pow((h[i]-h[dq[0]]), 2)+c;
        while((!dq.empty())&&dq.size()>=2&&slope(dq[dq.size()-2], dq[dq.size()-1])>=slope(dq[dq.size()-1], i)) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n] << "\n";
    return 0;
}