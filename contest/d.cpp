
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

void solve(){
    int a[1003]; int cnt[1003];
    vi ans; int num=0;
    memset(cnt, 0, sizeof cnt);
    memset(a, 0, sizeof a);
    int n; cin >> n;
    FOR(i, 0, n-1) cin >> a[i];
    for(int i=0;i<n;i++) cnt[a[i]]++;

    for(int i=0;i<n;i++){
        if(cnt[i]==0){
                ans.pb(i);
                cnt[a[i]]--;
                a[i] = i;
                cnt[i]++;
                i = -1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==i){ continue;}
        for(int j=i+1;j<n;j++){
            if(a[j]==i){
                for(int k=i+1;k<=1000;k++){
                    if(!cnt[k]){
                        a[j] = k; cnt[k]++;
                        ans.pb(j); num++;
                        cnt[i]--;
                        break;
                    }
                }
            }
        }

        ans.pb(i);
        cnt[a[i]]--;
        a[i] = i;
    
    }
    if(ans.empty()) cout << 0 << "\n";
    else cout << ans.size() << "\n";
    for(auto e:ans) cout << e+1 << " ";
    cout << "\n";



}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}