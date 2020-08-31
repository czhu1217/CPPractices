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
string s, t;
bool vis[30][30]; int ind[30], out[30];
int main(){
    memset(vis, 0, sizeof vis);
    cin >> s >> t;
    int n = s.size();
    for(int i=0;i<n;i++){
        int a = s[i]-'a', b = t[i]-'a';
        if(!vis[a][b]){
            vis[a][b] = 1; ind[b]++; out[a]++;
        }
        if(ind[b]>1||out[a]>1){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}