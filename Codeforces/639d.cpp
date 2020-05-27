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
ll n,m;
char a[1002][1002];
bool vis[1002][1002];
bool empr[1002], empc[1002];
ll ans=0;
void dfs(ll r, ll c){
    if(a[r][c]=='.')return;
    if(vis[r][c])return;
    vis[r][c]=1;
    if(r-1>0)  dfs(r-1, c);
    if(r+1<=n) dfs(r+1, c);
    if(c-1>0) dfs(r, c-1);
    if(c+1<=m) dfs(r, c+1);
}
void solve(){
    memset(vis, 0, sizeof vis);
    memset(empr, 1, sizeof empr);
    memset(empc, 1, sizeof empc);
    cin >> n >> m; bool imp=0;
    int rcnt=n, ccnt=m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    if((n==1||m==1)&&imp){
        return;
    }
    ll id=0;
    ll on;
    for(ll i=1;i<=n;i++){
        on = 0;
        for(ll j=1;j<=m;j++){
            if((!on)&&a[i][j]=='#'){rcnt--;on++;empr[i]=0;}
            else if(on==1&&a[i][j]=='.')on++;
            else if(on==2&&a[i][j]=='#'){
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(ll j=1;j<=m;j++){
        on = 0;
        for(ll i=1;i<=n;i++){
            if((!on)&&a[i][j]=='#'){on++;ccnt--;empc[j]=0;}
            else if(on==1&&a[i][j]=='.')on++;
            else if(on==2&&a[i][j]=='#'){
                cout << -1  << "\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(empr[i]){
            if(ccnt==0){
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(empc[i]){
            if(rcnt==0){
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i][j]=='#'&&!vis[i][j]){
                dfs(i, j);
                ans++;

            }
        }
    }


    cout << ans << "\n";

}
int main(){
    solve();
    return 0;
}