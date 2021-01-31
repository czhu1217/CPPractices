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
const int MM = 1e5+5;
int n, q, a[MM], p[MM], s[MM]; char c;
stack<int> st;
int main(){
    cin >> n >> q;
    FOR(i,1,n){
        cin >> c;
        a[i] = c-'A';
    }
    FOR(i, 1, n){
        p[i] = p[i-1];
        while(!st.empty()&&st.top()>a[i]){
            st.pop();
        }
        if(!st.empty()&&st.top()==a[i]) continue;
        else{
            p[i]++;
            st.push(a[i]);
        }
    }
    stack<int> st2;
    for(int i=n;i>0;i--){
        s[i] = s[i+1];
        while(!st2.empty()&&st2.top()>a[i]){
            st2.pop();
        }
        if(!st2.empty()&&st2.top()==a[i]) continue;
        else{
            s[i]++;
            st2.push(a[i]);
        }
    }
    // FOR(i, 1, n) cout << p[i] << " ";
    // cout << "\n";
    // FOR(i, 1, n) cout << s[i] << " ";
    // cout << "\n";
    int x, y;
    FOR(i, 1, q){
        cin >> x >> y;
        cout << p[x-1]+s[y+1] << "\n";
    }
    return 0;
}