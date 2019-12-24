//to do
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, m, s, si, cnt, lv[100005], step = 0, vis[100005], onpath[100005], degree[100005], deleted[100005];
vector<vector<int>> adj(1);
map<int, bool> pho;
queue<int> q;
void prunning(){
    int t;
    while(!q.empty()){
        t = q.front();
        deleted[t] = true;

        q.pop();
        vis[t] = true;
        for(auto e:adj[t]){
            if(!pho[e]&&degree[e]==1){
                q.push(e);
            }
            for(auto a:adj[e]){
                degree[a]--;
            }

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
        scanf("%d ", &p);
        pho[p] = true;
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
        if (!pho[i] && degree[i] == 1)
        {
            q.push(i);
            for(auto e:adj[i]){
                degree[e]--;
            }
        }
    }
    prunning();

    printf("%d\n", step);
    return 0;
}