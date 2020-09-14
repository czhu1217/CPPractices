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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
ll op;ll a, b;char c;bool pre;
vector<ll> v;
const ll MM = INT_MAX;
ll comp(){
    switch(op) {
      case '+': return a+b;
      case '-': return a-b;
      case '*': return a*b;
      case '/': return a/b;
      case '%': return a%b;
    }
}
void solve(){
    v.clear();
    char c; cin >> c;
    if(c-'0'>=0&&c-'0'<=9){
        pre = 0;
    }
    else{
        pre = 1;
    }
    while(c!='\n'){
        if(c-'0'<=9&&c-'0'>=0)
        v.push_back(c-'0');
        else v.push_back(c+MM);

        while(v.size()>=3){
            if(pre){
                op = (v[v.size()-3]); a= v[v.size()-2]; b=v[v.size()-1];
            }
            else{
                op = (v[v.size()-1]);a= v[v.size()-3];b= v[v.size()-2];
            }
            if(a<MM&&b<MM&&op>MM){
                op -= MM;
            v.pop_back();v.pop_back();v.pop_back();
            v.push_back(comp());}
            else break;

        }
        scanf("%c", &c);
        if(c==' ') scanf("%c", &c);
    }

    cout << v[0] << "\n";
}

int main(){
    for(ll i=1;i<=5;i++){
        solve();
    }

    return 0;
}