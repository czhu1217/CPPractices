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
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
 
#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
const ll MM = 1e5+5;
ll n, k; int a[MM]; ll dpc[MM], dpp[MM], psa[MM]; int root[MM][202], lmt[MM];
vector<int> v[MM];

int main(){
    psa[0]=0;
    memset(lmt, 0, sizeof lmt);
    cin >> n >> k; k++;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        psa[i] = psa[i-1]+a[i];
    }

    memset(dpp, 0, sizeof dpp);
    for(ll cnt=1;cnt<=k;cnt++){
        memset(dpc, -1, sizeof dpc);
        for(ll i=1;i<=n;i++){
            int temp = lmt[i];
            for(ll j=lmt[i];j<i;j++){
                ll tt = dpc[i];
                dpc[i] = max(dpc[i], dpp[j]+(psa[n]-psa[i])*(psa[i]-psa[j]));
                if(dpc[i]!=tt){ root[i][cnt] = j; temp = j; }
            }
            lmt[i] = temp;
            // cout << i << " " << cnt << " " << dpc[i]  << " " << root[i][cnt] << "\n";
        }
        swap(dpc, dpp);
    }
    cout << dpp[n] << "\n";
    for(ll i=k;i>1;i--){
        cout << root[n][i] << " ";
        n = root[n][i];
    }



    return 0;
}