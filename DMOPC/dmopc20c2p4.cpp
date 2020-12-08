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
const int MM = 5e5+5;
int n, m, b[MM], d[MM], cnt[MM], mi=INT_MAX;
bool solve(int k){
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(d[cnt++]>=b[i]) return false;
        if(d[cnt++]>=b[i]) return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    FOR(i, 1, n) cin >> b[i];
    sort(b+1, b+n+1);
    FOR(i, 1, m) cin >> d[i];
    cout << m << "\n";
    for(int i=1;i<=m;i++){
        int lo = 0, hi = MM;
        sort(d+1, d+1+i);
        int mid;
        while(lo!=hi){
            mid = ceil((lo+hi)/2);
            if(solve(mid)) lo = mid;
            else hi = mid-1;
        }
        cout << lo << "\n";
    }



    // int prev = 0;
    // for(int i=1;i<=m;i++){
    //     for(int j=1;i<=n;j++){
    //         if(b[j]>d[i]){
    //             if(!prev) prev = j;
    //             else{
    //                 if(cnt[j]<cnt[prev]) prev = j;
    //                 else if(b[j]<b[prev]) prev = j;
    //             }
    //         }
    //     }
    //     if(prev)
    //     cnt[prev]++;
    //     for(int j=1;j<=n;j++){
    //         mi = min(mi, cnt[j]);
    //     }

    // }

    return 0;
}