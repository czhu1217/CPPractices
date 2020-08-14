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
int T, r, c;
bool solv=false;
pair<int, int> path[405];
bool vis[23][23];
void search(int cur){
    bool ok=0;
    if(solv) return;
    if(cur>r*c){
        solv=true;
        printf("POSSIBLE\n");
        for(int i=1;i<=r*c;i++){
            printf("%d %d\n", path[i].first, path[i].second);
        }
        return;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(!vis[i][j]&&i!=path[cur-1].first&&j!=path[cur-1].second&&abs(i-path[cur-1].first)!=abs(j-path[cur-1].second)){
                path[cur]={i, j};
                vis[i][j]=true;
                search(cur+1);
                vis[i][j]=false;
            }
        }
    }
    
}
int main(){
    cin >> T;
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        solv=0;
        cin >> r >> c;
       for(int i=1;i<=r;i++){
           if(solv)break;
           for(int j=1;j<=c;j++){
               if(solv)break;
               memset(path, 0, sizeof path);
               path[1]={i, j};
               vis[i][j]=true;
               search(2);
               vis[i][j]=false;
           }
       }
       if(!solv){
           printf("IMPOSSIBLE\n");
       }

    }
    return 0;
}