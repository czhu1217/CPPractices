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
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int N;
const int MM = 4e5+5;
vector<int> adj[MM];
ll dis[MM], cnt[MM]; ll dia=0, num=0;
void dfs(int cur, int par){
    dis[cur]=0;cnt[cur]=1;
    for(auto e:adj[cur]){
        if(e!=par){
            dfs(e, cur);
            if(dis[cur]+dis[e]+1>dia){
                dia = dis[cur]+dis[e]+1;
                num = cnt[e]*cnt[cur];
            }
            else if(dis[cur]+dis[e]+1==dia){
                num += cnt[e]*cnt[cur];
            }
            if(dis[e]+1>dis[cur]){dis[cur] = dis[e]+1; cnt[cur]=cnt[e];}
            else if(dis[e]+1==dis[cur]){ cnt[cur] += cnt[e];}
        }
    }
}
int main(){
    memset(dis, 0, sizeof dis);
    cin >> N;
    for(int i=1,u, v;i<N;i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << dia+1 << " " << num;
    return 0;
}