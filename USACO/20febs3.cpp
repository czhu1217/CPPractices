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
vector<int> a, t;;
int n, ans=0;
void dfs(int cur, int par){
    t[cur] = a[cur];
    for(auto v:adj[cur]){
        if(v==par){
            continue;
        }
        dfs(v, cur);
        t[cur] = (t[cur]+12-t[v])%12;
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
    for(int i=1;i<=n;i++){
        dfs(i, 0);
        if(t[i]==1||t[i]==0){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;

}