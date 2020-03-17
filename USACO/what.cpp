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
typedef long long ll;
using namespace std;
vector<vector<int>> adj;
vector<int> a, t;
int n, ans=0, a1=0, a2=0, cnt1=0, cnt2=0;bool flag = true;
void dfs(int u, int par, int id){
    if(id) {
        a1 += a[u];
        cnt1++;}
    else {
        a2 += a[u];
        cnt2++;}
    for(auto v:adj[u]){
        if(v!=par){
            dfs(v, u, id^1);
        }
    }
}
int main(){
    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    t.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1, x, y;i<n;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0, 0);
    int dif = (a1%12-a2%12+12)%12;
    if((dif==1)||(dif==0)){
        ans += cnt1;
    }
    if((dif==11)||(dif==0)){
    ans += cnt2;}
    cout << ans << "\n";
    return 0;

}