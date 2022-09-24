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

int n, a[100005];
int rec[100005];
int save[100005];
int cnt[100005];
int mx, mx2;
int main(){
    cin >> n;
    FOR(i, 1, n){

        cin >> a[i];
        if(a[i]>mx){ rec[i] = 1; swap(mx, mx2); mx = a[i];}
        else if(a[i]>mx2){ save[i] = mx; mx2 = a[i];}
    }
    FOR(i, 1, n){
        if(save[i]){
            cnt[save[i]]++;
        }
    }
    FOR(i,1, n){
        int val = a[i];
        if(rec[i]) cnt[val]--;
    }
    int mxx = -2;
    int ans = 0;
    FOR(i, 1, n){
        if(cnt[i]>mxx){
            ans = i;
            mxx = cnt[i];
        }
    }
    cout << ans << "\n";
    return 0;

}