
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
const int MM = 2e6+5;
int cnt[MM], ans[MM], n; ll res=0;
int main(){
    memset(cnt, 0, sizeof cnt);
    memset(ans, 0, sizeof ans);
    cin >> n;
    FOR(i, 1, n){
        int t; cin >> t;
        cnt[t]++;
    }
    for(int i=1;i<MM;i++){
        for(int j=1;j*i<MM;j++){
            ans[i] += cnt[i*j];
        }
    }
    for(int i=1;i<MM;i++){
        if(ans[i]<=1)continue;
        res = max(res, (ll)ans[i]*i);
            }
    cout << res << "\n";
    return 0;
}