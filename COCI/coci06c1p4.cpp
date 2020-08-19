#include <bits/stdc++.h>
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
int r, c, sx, sy;
const int MM =55;
char a[MM][MM];
int m[MM][MM]; bool vis[MM][MM];
vpi fld;
bool check(int i, int j){
    if(i<=0||j<=0)return false;
    if(i>r||j>c) return false;
    if(a[i][j]=='X'||a[i][j]=='D')return false;
    return true;
}
bool check2(int i, int j){
    if(i==1&&j==6){
        i++; i--;
    }
    if(vis[i][j]) return false;
    if(i<=0||j<=0)return false;
    if(i>r||j>c) return false;
    if(a[i][j]=='X')return false;
    return true;
}
int main(){
    memset(vis, 0, sizeof vis);
    memset(m, 0x3f, sizeof m);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            if(a[i][j]=='*') fld.pb({i, j});
            if(a[i][j]=='S'){
                sx = i; sy = j;
            }
        }
    }

    for(auto e:fld){
        // cout << e.f << " " << e.s << "\n";
        queue<pair<pair<int, int>, int>> q;
        q.push({e, 0});
        m[e.f][e.s] = 0;
        while(!q.empty()){
            int i = q.front().f.f, j = q.front().f.s, v = q.front().s;
            q.pop();
            if(check(i+1, j)){
                if(m[i+1][j]>v+1){
                    m[i+1][j] = v+1;
                    q.push({{i+1, j}, v+1});
                }
            }
            if(check(i-1, j)){
                if(m[i-1][j]>v+1){
                    m[i-1][j] = v+1;
                    q.push({{i-1, j}, v+1});
                }
            }
            if(check(i, j+1)){
                if(m[i][j+1]>v+1){
                    m[i][j+1] = v+1;
                    q.push({{i, j+1}, v+1});
                }
            }
            if(check(i, j-1)){
                if(m[i][j-1]>v+1){
                    m[i][j-1] = v+1;
                    q.push({{i, j-1}, v+1});
                }
            }
        }

    }
    // FOR(i, 1, r){
    //     FOR(j, 1, c){
    //         if(m[i][j]>100) cout << "X ";
    //         else cout << m[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    queue<pair<pi, int>> q;
    q.push({{sx, sy}, 0});
    while(!q.empty()){
        int i = q.front().f.f, j = q.front().f.s, v = q.front().s;
        q.pop();
        if(a[i][j] == 'D'){
            cout << v << "\n";
            return 0;
        }
        if(check2(i+1, j)){
            if(m[i+1][j]>v+1||a[i+1][j]=='D'){
                q.push({{i+1, j}, v+1});
                vis[i+1][j] = 1;
            } 
        }
        if(check2(i-1, j)){
            if(m[i-1][j]>v+1||a[i-1][j]=='D'){
                q.push({{i-1, j}, v+1});
                vis[i-1][j] = 1;
            } 
        }
        if(check2(i, j+1)){
            if(m[i][j+1]>v+1||a[i][j+1]=='D'){
                 q.push({{i, j+1}, v+1});
                 vis[i][j+1] = 1;
            }
        }
        if(check2(i, j-1)){
            if(m[i][j-1]>v+1||a[i][j-1]=='D'){
                q.push({{i, j-1}, v+1});
                vis[i][j-1] = 1;
            } 
        }

    }
    cout << "KAKTUS\n";
    
    
    return 0;
}