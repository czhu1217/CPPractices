#include <stdio.h>
#include <vector>
using namespace std;
int N, R, M, t, team, scnt, bcnt;
vector<int> v, id;
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int p, int te){
    vis[p] = true;
    v[p] = te;
    for(int i=0;i<adj[p].size();i++){
        if(!vis[adj[p][i]])
        dfs(adj[p][i], 0-te);
    }
    return;
}

int main(){
    scanf("%d %d",&N, &R);
    adj.resize(N+1);
    v.resize(N+1);
    vis.resize(N+1);
    id.resize(N+1);

    for(int i=1;i<=N;i++){
        scanf("%d", &M);

        for(int j=0;j<M;j++){
            scanf("%d", &t);
            adj[i].push_back(t);
            id[t]++;
            adj[t].push_back(i);
        }
    }
    dfs(R, 1);

    for(int i=1;i<=N;i++){
        if(id[i]==0){
            if(v[i]==1){
                scnt++;
            }
            else{
                bcnt++;
            }
        }
    }
    printf("%d %d", scnt, bcnt);
    return 0;
 
    
}
