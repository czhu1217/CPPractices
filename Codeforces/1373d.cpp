
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
const int MM = 2e5+5;
int a[MM]; ll od[MM], ev[MM];

void solve(){

    int n; 
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0, cur=0; ll sum=0;
    for(int i=0;i<n;i+=2) sum += a[i];
    for(int i=1;i<n;i+=2){
        if(a[i]-a[i-1]+cur>0){
            cur += a[i]-a[i-1];
            // cout << a[i] - a[i-1] << "\n";
            ans = max(ans, cur);
        }
        else cur = 0;

    }
    cur = 0;
    for(int i=2;i<n;i+=2){
        if(a[i-1]-a[i]+cur>0){
            cur += a[i-1]-a[i];
            ans = max(ans, cur);
        }
        else cur = 0;
    }
    // cout << ans << "\n";
    cout << sum+ans << "\n";



}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}