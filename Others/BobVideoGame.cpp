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
int N, M, T;
int adj[305][305];
queue<int> qu;
bool vis[305];
int path[305][305];
int main(){
    memset(path, 0x3f, sizeof(path));
    cin >> N >> M >> T;
    for(int i=1;i<=M;i++){
        int u, v, w;
        cin >> u >> v >> w;
        path[u][v] = w;
        
    }
    for(int k=0; k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=0;j<=N;j++){
                path[i][j] = min(max(path[i][k], path[k][j]),path[i][j] );
            }
        }
    }
    for(int i=1;i<=T;i++){
        int a, b;
        cin >> a >> b;
        if(path[a][b]==0x3f3f3f3f){
            cout << -1 << "\n";
        }
        else{
            cout << path[a][b] << "\n";
         }
    }
    return 0;
}