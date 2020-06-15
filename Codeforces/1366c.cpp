
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
bool vis[33][33];
void solve(){
    int ans=0;
    memset(vis, 0, sizeof vis);
    int a[33][33];
    
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     if(vis[i][0])break;
    //     int j=0, temp=i; int cnt[2];
    //     memset(cnt, 0, sizeof cnt);
    //     while(j<m&&temp>=0){
    //         cout << temp << " " << j << "  " << n-1-temp << " " << m-1-j << "\n";
    //         vis[temp][j] = 1;
    //         vis[n-1-temp][m-1-j]=1;
    //         cnt[a[temp][j]]++;
    //         cnt[a[n-1-temp][m-1-j]]++;
    //         j++; temp--;
    //     }
    //     if(cnt[0]>cnt[1]) ans+=cnt[1];
    //     else ans += cnt[0];
    //     cout << "\n";
    // }
    int lim = n-1+m-1;

    for(int k=0;k<=lim;k++){
        if(k*2==lim)continue;
        int cnt[2];
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<=min(n, k);i++){
            int j = k-i;
            if(vis[i][j])continue;
            if(i>=n||j>=m)continue;
            // cout << i << " " << j << "  " << n-i-1 << " " << m-j-1 << "\n";

            cnt[a[i][j]]++;
            cnt[a[n-i-1][m-j-1]]++;
            vis[i][j]=1; vis[n-i-1][m-j-1]=1;
        }
        // cout << cnt[0] << " " << cnt[1] << "\n";
        if(cnt[0]<cnt[1]) ans += cnt[0];
        else ans += cnt[1];
    }
    cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}