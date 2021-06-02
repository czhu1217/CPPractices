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
 

const int MM = 5e6+5;
int ti, a, b; bool dp[MM], vis[MM];
bool fun(int x, int used){
    if(x<0||x>ti) return 0;
    if(vis[x]) return dp[x];
    vis[x] = 1;
    if(fun(x-a, used) || fun(x-b, used)){
        dp[x] = 1;
    }
    if(!used){
        if(fun(x*2, 1)||fun(x*2+1, 1)){
            dp[x] = 1;
        }
    }
    return dp[x];

}
int main(){
    ifstream cin("feast.in");
    ofstream cout("feast.out");
    cin >> ti >> a >> b;

    dp[0] = 1;
    for(int t = ti; t>=0;t--){
        if(fun(t, 0)){
            cout << t << "\n";
           return 0;
        }
    }

 

}