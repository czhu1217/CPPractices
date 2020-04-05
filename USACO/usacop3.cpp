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
#include <fstream>
using namespace std;
typedef long long ll;
int N;
const int MM = 1e5+2;
int x[100005], y[100005];
vector<int> adj[100005];
bool vis[MM];
queue<int> qu;
int ans = 0;
int dfs(int idx, int cnt){
    if(cnt>ans) ans = cnt;
    vis[idx] = true;
    int t = 0;
    for(auto e:adj[idx]){
        if(!vis[e]){
            dfs(e, cnt+1);
        }
    }
}
int main(){
    ifstream cin("moop.in");
     ofstream cout("moop.out");
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if((x[i]<=x[j]&&y[i]<=y[j])||(x[i]>=x[j]&&y[i]>=y[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=N;i++){
        memset(vis, false, sizeof(vis));
        dfs(i, 0);
    }
    cout << N-ans << "\n";
    return 0;

}