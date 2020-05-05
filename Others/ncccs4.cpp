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
int N, M, K, S, T;
const int MM = 1e5+2; int lst;
queue<int> q;
struct event{
    int u, v, w, op;
    bool operator<(const event &e){
        return w<e.w||(w==e.w&&op<e.op);
    }
};bool vis[MM]; ll ans=0;
vector<event> vec; unordered_set<int> adj[MM];
void update(int id){
    int u=vec[id].u, v = vec[id].v, w=vec[id].w, op=vec[id].op;
    if(op==1){
       adj[u].insert(v);
    }
    else{
        adj[u].erase(v);
    }
    return;
    
}
bool bfs(int s, int t){
    memset(vis, 0, sizeof vis);
    q.push(s); vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=1; q.push(v);
                
            }
        }
    }
    return vis[t];
}
int main(){
    cin >> N >> M >> K;
    cin >> S >> T;
    for(int i=1;i<=M;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vec.push_back({a, b, c, 1}); vec.push_back({a, b, d+1, -1});


    }
    sort(vec.begin(), vec.end());

    for(int i=0;i<vec.size();i++){
        int cur = vec[i].w;
        bool flg = vis[T];
        update(i);
        while(i+1<vec.size()&&vec[i+1].w==cur){update(i+1);i++;}
        if(bfs(S, T)){
            ans += (flg?cur-lst:1);

        }
        else if(flg) ans += cur-lst-1;
        lst=cur;
    }
    cout << ans << "\n";
    return 0;



}