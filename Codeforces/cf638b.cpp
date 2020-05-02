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
using namespace std;
typedef long long ll;
int N, K; int a[102];
bool vis[102];
void solve(){
    vector<int> v;
    memset(vis, 0, sizeof vis);
    int cnt=0;
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        if(!vis[a[i]]){
            vis[a[i]]=1;cnt++;
        }
    }
    if(cnt>K){
        cout << -1 << "\n";
        return ;
    }
    for(int i=1;i<=100;i++){
        if(vis[i])v.push_back(i);
    }
    while(v.size()<K){
        v.push_back(v.back());
    }
    int len=0;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(v[len%K]);
        len++;
        while(a[i]!=v[(len-1)%K]){
            ans.push_back(v[len%K]);
            len++;
        }
    }
    cout << ans.size() << "\n";
    for(auto e:ans){
        cout << e << " ";
    }
    cout << "\n";

    
}
int main(){
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}