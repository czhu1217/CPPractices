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
#include <unordered_map>
#include <climits>
using namespace std;
typedef long long ll;
bool vis[200005], vis2[200005]; vector<int> pa, pb;
        vector<int> adj[200005];
int par[200005]; 

void bfs(int s, int t, vector<int> &p){
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();
        if(u==t)break;
        for(auto e:adj[u]){
            if(!vis[e]){
                q.push(e);
                vis[e]=1;
                par[e] = u;
            }
        }
    }
    int i = t;
    while(i!=-1){
        p.push_back(i);
        i = par[i];
    } 
}

void bfs2(int s, int t, vector<int> &p){
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();

        if(u==t)break;bool brk=0;
        for(auto e:adj[u]){
            if(e==t){q.push(e);
            vis2[e]=1;
            par[e]=u;
            brk=1;
            break;}
        }
        if(brk)break;
        for(auto e:adj[u]){

            if(vis[e]&&!vis2[e]){
                q.push(e);
                vis2[e]=1;
                par[e] = u;
            }
        }
        for(auto e:adj[u]){
            if(!vis2[e]){
                q.push(e);
                vis2[e]=1; par[e]=u;
            }
        }
    }
    int i = t;
    while(i!=-1){
        p.push_back(i);
        i = par[i];
    } 
}
int main(){
    int t;cin >> t;
    while(t--){
        pa.clear();pb.clear();
        memset(vis, 0, sizeof vis);
        memset(vis2, 0, sizeof vis2);
        int n, m, a, c, b;
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        int p[200005];
        for(int i=1;i<=m;i++){
            scanf("%d", &p[i]);
        }
        sort(p+1, p+m+1);
        for(int i=1;i<=m;i++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        par[a]=-1;vis[a]=1;
        bfs(a, b, pa); 
        par[b]=-1;vis2[b]=1;
        bfs2(b, c, pb);

         map<pair<int, int>, bool> ma; int dup=0;
        for(int i=0;i<pa.size()-1;i++){ ma[make_pair(pa[i+1], pa[i])]=1;}
        for(int i=0;i<pb.size()-1;i++){
            if(ma[{pb[i], pb[i+1]}]||ma[{pb[i+1], pb[i]}]){
                dup++;
            }
        }
        ll sum=0;
        for(int i=1;i<=dup;i++){
            sum += 2*p[i];
        }
        for(int i=dup+1; i<pa.size()-1+pb.size()-1-2*dup+dup+1;i++){
            sum += p[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}