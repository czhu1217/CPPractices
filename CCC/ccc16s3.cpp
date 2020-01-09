#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
int n, m, s, si, cnt, vis[100005], degree[100005], deleted[100005], cur;
int mx=0;
long long ans=0;
vector<vector<int>> adj(1);
map<int, bool> pho;
queue<int> q;
void prunning(){
    while(!q.empty()){
        int t = q.front();
        deleted[t] = true;
        q.pop();
        for(auto e:adj[t]){ 
            if((!pho[e])&&(degree[e]==1)&&(!vis[e])){
                q.push(e);
                vis[e] = true;
                for(auto a:adj[e]){
                degree[a]--;
                
            }
            degree[e]--;
            }
            

        }

    }
}
void dfs(int x, int cnt){

    if(cnt>mx){
        mx = cnt;
        cur = x;

    }
    vis[x] = true;
    for(auto e:adj[x]){
        if(!vis[e]&&!deleted[e]){
            dfs(e, cnt+1);
        }

    }
}

int main()
{
    scanf("%d %d", &n, &m);
    adj.resize(n);
    cnt = m;
    for (int i = 0, p; i < m; i++)
    {
        scanf("%d", &p);
        pho[p] = true;
        cur = p;
    }
    for (int i = 0, a, b; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        degree[a]++;
        degree[b]++;
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if ((!pho[i]) && degree[i] == 1)
        {
            q.push(i);
        
            for(auto e:adj[i]){
                degree[e]--;
            }
            degree[i]--;
            vis[i] = true;
        }
    }
    prunning();
    for (int i = 0; i < 2; i++)
    {
        memset(vis, false, sizeof(vis));
        dfs(cur, 0);
    }
    for(int i=0;i<n;i++){
        if(degree[i]&&(!deleted[i]))ans += degree[i];
    }
    ans -= mx;


    printf("%lld\n", ans);
    return 0;
}