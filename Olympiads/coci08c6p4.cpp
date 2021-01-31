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
const int MM = 1e4+5;
int n, a[MM], cnt[3];
int x;
vector<int> v[3];
vector<int> ans;
int main(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        v[a[i]%3].pb(a[i]);
    }

        while(!v[1].empty()){
            if(v[0].size()>1){ ans.pb(v[0].back()); v[0].pop_back();}
            ans.pb(v[1].back()); v[1].pop_back();
        }
        if(!v[0].empty()){ ans.pb(v[0].back()); v[0].pop_back();}
        while(!v[2].empty()){
            ans.pb(v[2].back()); v[2].pop_back();
            if(v[0].size()>0){ ans.pb(v[0].back()); v[0].pop_back();}

        }
    if(!v[0].empty()||!v[1].empty()||!v[2].empty()){
                    cout << "impossible\n";
            return 0;
    }
    for(int i=1;i<ans.size();i++){
        if((ans[i]+ans[i-1])%3==0){
            cout << "impossible\n";
            return 0;
        }
    }

    for(auto e:ans) cout << e << " ";
    cout << "\n";
    return 0;
}