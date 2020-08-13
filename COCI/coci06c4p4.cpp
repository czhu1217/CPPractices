
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
const int LOG = 1e9+7;
int n, c;
ll cur[10005], pre[10005];
int main(){
    cin >> n >> c;
    memset(pre, 0, sizeof pre);
    if(n==1){cout << "0\n"; return 0;}
    pre[0] = 1; pre[1] = 1;
    for(int i=3;i<=n;i++){
        memset(cur, 0, sizeof cur);
        for(int j=0;j<=min(c, i*(i-1)/2);j++){
            cur[j] = ((cur[j]+pre[j])%LOG + cur[j-1])%LOG;
            if(j-i>=0) cur[j] = (cur[j] - pre[j-i]+LOG)%LOG;
        }
        swap(cur, pre);
    }
    cout << pre[c] << "\n";
    return 0;

}