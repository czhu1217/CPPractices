#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int M, N;
int a[1003][1003];
bool vis[1003][1003];
bool flag = false;

map<int, vector<pair<int, int> > > m;
int main(){
    cin >> M >> N;
    queue<int> q;
    int lookup;
    memset(vis, false, sizeof(vis));
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &a[i][j]);
            m[a[i][j]].push_back({i, j});
        }
    }
    lookup = M*N;
    q.push(M*N);
    while(!q.empty()){
        lookup = q.front();
        q.pop();
        for(auto e:m[lookup]){
            if(vis[e.first][e.second]) continue;
            q.push(e.first*e.second);
            vis[e.first][e.second] = true;
        }
        if(lookup==a[1][1]){
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
  
    



}