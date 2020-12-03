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
int n; const int MM = 2e6+2;
int a[MM], ans[MM];
int s=0;
int main(){
    cin >> n;int x;
    FOR(i, 1, n){
        cin >> a[i];
        if(!s){
            s++; ans[s] = a[i]; continue;
        }
        if(a[i]==ans[s])continue;
        if(s==1){
            s++;
            ans[s] = a[i]; continue;
        }
        if((a[i]-ans[s])*(ans[s]-ans[s-1])<0){
            s++;
            ans[s] = a[i];
            continue;
        }
        ans[s] = a[i];
    }
    cout << s << "\n";
   

    return 0;
}