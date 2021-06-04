#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define pb push_back
#define f first
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const int MM = 500;
string a, b;
void fun(string s){
    // if(mp[s]) return;
    // ll ans = INT_MAX;
    // if(s.size()==a.size()){
    //     int cnt = 0;
    //     FOR(i, 0, s.size()-1) if(s[i]!=a[i]) cnt++;
    //     mp[s] = cnt;
    //     return;
    // }
    // for(int i=0;i<s.size();i++){
    //     string str = s.erase(i, 1);
    //     fun(str);
    //     ans = min(ans, (ll)mp[str]+1);
    // }
    // mp[s] = ans;



}
int main(){
    cin >> a >> b ;
    if(a.size()>b.size()) swap(a, b);
    //a is the needle, b is the heystack
    fun(b);
    // cout << mp[b] << "\n";
    

    return 0;
}