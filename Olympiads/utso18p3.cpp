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
int n, t, k, v, a[MM], temp;
vector<int> ve;
int main(){
    cin >> n >> t >> k >> v;
    FOR(i, 1, v){
        cin >> temp;
        a[temp]++;
    }
    int cnt=0;
    for(int i=1;i<=t;i++){
        if(a[i]) cnt++;
    }
    int ans=0;
    ans += max(0, k-cnt);
    temp = ans;
    int last = 0;
    for(int i=t;i>0;i--){
        if(temp&&!a[i]){ a[i]++; temp--;}
        if(!a[i]) ve.pb(i);
    }
    cnt = max(cnt, k);
    for(int i=t+1; i<=n;i++){
        if(!a[i]) ve.pb(i);
        cnt += a[i];
        cnt -= a[i-t];
        if(cnt>=k){
            continue;
        }
        else{
             ans++;
             a[ve.back()]++;
             ve.pop_back();
             cnt++;

        }

    }
    cout << ans << "\n";

    return 0;
}