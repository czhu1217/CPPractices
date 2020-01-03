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
    for(int i=0;i<Q;i++){
        cin >> s[i] >> spd[i];
    }
    dp[0] = 0;

    for(int i=0;i<Q;i++){
        int mx = 0;
        for(int j=0;j+i<=Q&&j<M;j++){
            mx = max(mx, spd[i+j]);
            int alt = dp[i] + mx;
            if(alt<dp[i+j+1]){
                dp[i+j+1] = alt;
                pre[i+j+1] = i;
            }
        }
    }
    cout << "Total Time: " << dp[Q] << "\n";
    int idx = Q;
    vector<int> v;
    while(true){
        v.push_back(idx);
        if(idx==0)break;
        idx = pre[idx];
    }
    reverse(v.begin(), v.end());
       for (int i = 0; i < v.size() - 1; i++){
        for (int j = v[i]; j < v[i + 1]; j++){
            cout << s[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}