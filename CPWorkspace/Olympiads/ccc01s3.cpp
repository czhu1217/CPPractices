#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string s;
bool adj[30][30], vis[30][30];
string road[30][30];
int cnt = 0;
bool connected(int x, int y){


    if(x==y) return true;
    for(int i=0;i<26;i++){
        if(adj[x][i]&&(!vis[x][i])){
            vis[x][i] = true;
            if(connected(i, y)) return true;

        }
    }
    return false;
}

int main(){

    memset(adj, false ,sizeof(adj));

    while(true){
        string s;
      
        cin >> s;
        // cout << s[0] << " " << s[1] << "\n";
          if(s=="**") break;
        road[s[0]-'A'][s[1]-'A'] = s;
        road[s[1]-'A'][s[0]-'A'] = s;
        adj[s[0]-'A'][s[1]-'A'] = true;
        adj[s[1]-'A'][s[0]-'A'] = true;

    }


    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){

            memset(vis, false, sizeof(vis));
            if(adj[i][j]){
                adj[i][j] = false;
                adj[j][i] = false;

                if(!connected(0, 1)){
                    cout << road[i][j]<< "\n";
                    cnt++;

                }
                adj[i][j] = true;
                adj[j][i] = true;
            }

        }
    }
    printf("There are %d disconnecting roads.\n", cnt);
    return 0;
}