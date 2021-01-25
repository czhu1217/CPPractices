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
const int MM = 1e6+5;
int n, k; bool c[2*MM]; int a[2*MM];
int cnt, mx;
stack<int> st;
int main(){
    cin.tie(); cin.sync_with_stdio(0);
    cin >> n >> k;
    int t;
    FOR(i,1,k){
        cin >> t;
        c[t] = 1;
    }
    FOR(i, 1, k+1){
        cin >> t; a[t]=i;
    }
    FOR(i, 1, n){
        if(a[i]){
            st.push(a[i]);
            a[i] = 0;
        } 
        if(c[i]&&!st.empty()){
            t = st.top();
             st.pop();
             c[i] = 0;
        }
        if(i==n&&cnt==0) {i=0; cnt++;}
    }   
    cout << (st.top()) << "\n";
    return 0;
}