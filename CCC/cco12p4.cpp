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
typedef pair<pair<int, int>, int> ppi;
 
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
int n, rs, cs, rf, cf, a[100005];
bool  vis[100005][85];
bool check(int i, int j){
    if(vis[i][j]) return 0;
    if(i<=0||j<=0)return 0;
    if(i>n||j>a[i]) return 0;
    return 1;
}
int main(){
    memset(vis, 0, sizeof vis);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> rs >> cs >> rf >> cf;
    queue<ppi> q;
    q.push({{rs, cs}, 0});
    vis[rs][cs] = 1;
    while(!q.empty()){
        int i = q.front().f.f, j = q.front().f.s, v = q.front().s;
        // cout << i << " " << j <<  " " << v << "\n";
        if(i==rf&&j==cf){
            cout << v << "\n";
            return 0;
        }
        q.pop();
        if(check(i+1, j)){
            // printf("push %d %d\n", i+1, j);
            q.push({{i+1, j}, v+1}); vis[i+1][j] = 1;
        }
        else if(i==n){}
        else if(a[i+1]<j){
            if(!vis[i+1][a[i+1]]){
                vis[i+1][a[i+1]] = 1;
                q.push({{i+1, a[i+1]}, v+1});
                // printf("push %d %d\n", i+1, a[i+1]);
            }
        }
        if(check(i-1, j)){
            q.push({{i-1, j}, v+1}); vis[i-1][j] = 1;
            // printf("push %d %d\n",i-1, j);
            
        }
        else if(i==1){}
        else if(a[i-1]<j){
            if(!vis[i-1][a[i-1]]){
                q.push({{i-1, a[i-1]}, v+1});
                vis[i-1][a[i-1]] = 1;
                // printf("push %d %d\n", i-1, a[i-1]);
            }
        }
        if(check(i, j+1)){
            q.push({{i, j+1}, v+1}); vis[i][j+1] = 1;
            // printf("push %d %d\n", i, j+1);
        }
        else if(i==n){}
        else if(j==a[i]){
            if(!vis[i+1][1]){
                q.push({{i+1, 1}, v+1});
                vis[i+1][1]  = 1;
                // printf("push %d %d\n",i+1, 1);
            }
        }
        if(check(i, j-1)){
            q.push({{i, j-1}, v+1}); vis[i][j-1] = 1;
            // printf("push %d %d\n",i, j-1);
        }
        else if(i==1){}
        else if(j==1&&!vis[i-1][a[i-1]]){
            q.push({{i-1, a[i-1]}, v+1});
            vis[i-1][a[i-1]] = 1;
            // printf("push %d %d\n", i-1, a[i-1]);
        }
    }
    
    return 0;
}