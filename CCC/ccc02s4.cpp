#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int M, Q, dp[105],  pre[105], spd[105]; 
string s[105];

int main(){
    cin >> M >> Q;
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1;i<=Q;i++){
        cin >> s[i] >> spd[i];
    }
    dp[0] = 0;

    for(int i=1;i<=Q;i++){
        int mx = spd[i];
        for(int j=i-1;j>=0&&i-j<=M;j--){
            int alt = dp[j] + mx;
            if(alt<dp[i]){
                dp[i] = alt;
                pre[i] = j;
            }
            mx = max(mx, spd[j]);
        }
    }
    cout << "Total Time: " << dp[Q] << "\n";
    int idx = Q;
    vector<int> v;
    while(true){
        if(idx==0)break;
        v.push_back(idx);
        idx = pre[idx];
    }
    reverse(v.begin(), v.end());
    int cnt = 1;
    for(auto e:v){
        while(cnt<=e){
            cout << s[cnt] << " ";
            cnt++;
        }
        cout << "\n";
    }
    return 0;
}