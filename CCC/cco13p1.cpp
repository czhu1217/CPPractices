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
ll x; vector<int> ans;
int main(){
    cin >> x;
    for(int i=2;i<x;i++){
        vector<int> v;
        ll t = x;
        while(t){
            v.pb(t%i);
            t /= i;
        }
        for(int j=0;j<=v.size()/2;j++){
            if(v[j]!=v[v.size()-1-j]) break;
            if(j==v.size()/2){
                ans.pb(i);
            }
        }
    }
    for(auto e:ans) cout << e << "\n";
    return 0;
}