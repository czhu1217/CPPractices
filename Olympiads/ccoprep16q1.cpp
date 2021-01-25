//histogram, max rectangle area
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
const int MM = 1003;
int m, n, a[MM], ans;
void solve(){
    memset(a, 0, sizeof a);
    stack<pi> st;
    ans=0;
    char u;
    cin >> m >> n;
    FOR(i,1,m){
        FOR(j, 1, n){
            cin >> u;
            if(u=='F'){
                a[j]++;
            }
            else a[j]=0;
        }
        // FOR(i, 1, n) cout << a[i] <<" ";
        // cout << "\n";
        FOR(j, 1, n+1){
            int last=j, cur;
            while((!st.empty())&&a[j]<st.top().f){
                last = st.top().s;
                cur = (j-st.top().s)*st.top().f;
                ans = max(cur, ans);
                // cout << ans << "\n";
                st.pop();
            }
            if(st.empty()||a[j]>st.top().f){
                // cout << j << "\n";
                st.push({a[j], last});
            }
        }
    }
    cout << ans*3 << "\n";

}

int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}