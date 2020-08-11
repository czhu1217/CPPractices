
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>
#define f first
#define s second
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
int a[MM], cnt[MM], fre2, fre4, fre6, fre8;

void solve(){
    bool pos=0, s=0, r=0; int r1, r2, s1;
    memset(cnt, 0, sizeof cnt);
    int n; cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    for(int i=1;i<MM;i++){
        if(cnt[i]>=8)fre8++;
       else if(cnt[i]>=6) fre6++;
       else if(cnt[i]>=4)fre4++;
       else if(cnt[i]>=2)fre2++;
    }
    int q; cin >> q;

    for(int i=1;i<=q;i++){

        char c; int x;
        cin >> c >> x;
        if(cnt[x]>=8)fre8--;
        else if(cnt[x]>=6) fre6--;
        else if(cnt[x]>=4)fre4--;
        else if(cnt[x]>=2)fre2--;
        if(c=='+'){
            cnt[x]++;

        }
        else{
            cnt[x]--;
        }
        if(cnt[x]>=8)fre8++;
        else if(cnt[x]>=6)fre6++;
        else if(cnt[x]>=4)fre4++;
        else if(cnt[x]>=2)fre2++;
                // cout << fre2 << " " << fre4 << " " << fre6 << "\n";
        if(fre8) cout << "YES\n";
        else if(fre6>=2)cout << "YES\n";
        else if((fre6&&fre4)||(fre6&&fre2)) cout << "YES\n";
        else if(fre4>=2)cout << "YES\n";
        else if(fre4&&fre2>=2) cout << "YES\n";
        else cout << "NO\n";

    
    }



}
int main(){
    solve();
    return 0;
}