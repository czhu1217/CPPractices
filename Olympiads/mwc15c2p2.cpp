//monotonic stack
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
int n, a[MM], ans;
stack<pi> st;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    FOR(i, 1, n){
        ans=0;
        int last=1;
        cin >> a[i];
        queue<pi> temp;
        while((!st.empty())&&st.top().f<=a[i]) st.pop();
        if(!st.empty()) last = st.top().s;
        while(!temp.empty()){
            st.push(temp.front());
            temp.pop();
        }
        st.push({a[i], i});
        cout << i-last << " ";
    } 
    cout << "\n";
    return 0;
}