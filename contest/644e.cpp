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
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
int a[55][55]; bool vis[55][55], posi[55][55];
int n;
bool row[55], col[55];
bool dfs(int ro, int co){
    if(vis[ro][co])return posi[ro][co];
    vis[ro][co] = 1;
    bool flg=0;
    if(ro==n||co==n){ flg= true;}
    else if(ro+1<=n&&a[ro+1][co]){
        if(dfs(ro+1, co))flg= true;
    }
    else if(co+1<=n&&a[ro][co+1]){
        if(dfs(ro, co+1))flg= true;
    }
    posi[ro][co] = flg;
    return posi[ro][co];
 
}
void solve(){
    memset(posi, 0, sizeof(posi));
    memset(vis, 0, sizeof vis);
    bool pos=1;
    memset(col, 0, sizeof col); memset(row, 0, sizeof row);
    cin >> n;
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c;
            if(c=='1')a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]&&!vis[i][j]){
                dfs(i, j);
            }
            if(a[i][j]&&vis[i][j]&&(!posi[i][j])){
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
 
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}