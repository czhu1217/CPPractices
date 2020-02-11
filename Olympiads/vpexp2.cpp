#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
pair<int, int> par[1000002]; int dp[10000002][2], day[1000002][2]; bool vis[1000004];
vector<pair<int, int>> adj[100005];
int N, D;
map<int, int> edge;
void dfs(int pos, int pa){
    for(auto e:adj[pos]){
        if(e.first!=pa){
            par[e.first] = {pos, e.second};
            printf("%d is parent of %d\n", pos, e.first);
            dfs(e.first, pos);
        }
    }
}
int tot = 0;
void find1(int n){
    if(n == 1) {
        vis[1] = true;
        return ;
    }
    vis[n] = true;
    find1(par[n].first);

}
int find2(int n){
    if(vis[n]) return  n;
    return find2(par[n].first);
    // return -1;
    

}
int dis(int a, int rt){
    if(a==rt) return tot;
    

}
int lca(int a, int b){
    tot = 0;
    memset(vis, false, sizeof(vis));
    find1(a);
    int rt = find2(b);
    tot = dis(a, rt) + dis(b, rt);
    return tot;
}
int main(){
    cin >> N >>D;
    for(int i=0, x, y, w; i<N-1;i++){
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});

    }
    par[1] = {1, 0};
    dfs(1, 1);
    for(int i=0, x, y; i<D;i++){
        // cout << " ? " << endl;
        cin >>x >>y;
        day[i][0] = x;
        day[i][1] = y;
        if(i==0){
          
            dp[0][0] = lca(1,x) + lca(x, y);
            dp[0][1] = lca(1, y) + lca(x, y);
        }
        else{
        dp[i][0] = min(dp[i-1][0]+lca(day[i-1][0], x), day[i-1][1]+lca(day[i-1][1], x)) + lca(y, x);
        dp[i][1] = min(dp[i-1][1]+lca(day[i-1][1], y), day[i-1][0]+lca(day[i-1][0], y))+lca(x, y);
        cout << dp[i][1] << endl;
        }

    }
    cout << min(dp[D-1][0], dp[D-1][1]) << endl;
    return 0;




    
}
