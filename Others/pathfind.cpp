
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
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
int n, m, k;
map<int, map<int, bool>> vis, ava;
const int MM = 5e5+5;
vpi v; int id=0;
bool touch[MM][4];
void dfs(int r, int c, int id){
    if(!ava[r][c])return;
    if(vis[r][c]) return;
    if(r>n)return; if(r<1)return; if(c>m)return; if(c<1)return;
    vis[r][c]=1;
    if(r==1) touch[id][0]=1;
    if(r==n) touch[id][1] = 1;
    if(c==1) touch[id][2]=1;
    if(c==m) touch[id][3]=1;
    // cout << r << " " << c << "\n";
    dfs(r+1, c, id); dfs(r-1, c, id);  dfs(r+1, c-1, id); dfs(r+1, c+1, id); 
    dfs(r, c+1, id); dfs(r, c-1, id); dfs(r-1, c-1, id); dfs(r-1, c+1, id); 

}
int main(){
    memset(touch, 0, sizeof touch);
    cin >> n >> m >> k;
    for(int i=1, r, c;i<=k;i++){
        cin >> r >> c;
        v.pb({r, c});
        ava[r][c]=1;
    }
    for(auto e:v){
        if(!vis[e.f][e.s]){
            // cout << id << " " << e.f << " " << e.s << "\n";
            dfs(e.f, e.s, id);
            id++;
        }
    }
    //0 top, 1 buttom, 2 left, 3 right
    for(int i=0;i<id;i++){
        bool a, b, c, d;
        a = touch[i][0], b = touch[i][1], c = touch[i][2], d=touch[i][3];
        if(a&&b){
            cout << "NO\n";
            return 0;
        }
        if(a&&c){
            cout << "NO\n";
            return 0;
        }
        if(c&&d){
            cout << "NO\n";
            return 0;
        }
        if(b&&d){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}
