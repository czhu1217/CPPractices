
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
const int MM = 3e5+5;
int n;
string st; int a[MM], pre[MM], suf[MM];
void solve(){
    cin >> n;
    cin >> st;

    for(int i=0;i<n;i++){
        if(st[i]=='L') a[i+1]=1;
        else a[i+1] = 0;
    }
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    for(int i=n;i>0;i--){
        suf[i] = suf[i+1]+a[i];
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        int temp;
        temp = pre[i-1]+n-i-suf[i+1];
        if(temp<ans)ans=temp;

    }
    cout << ans << "\n";



}
int main(){
    solve();
    return 0;
}