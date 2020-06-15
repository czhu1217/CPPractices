
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
int n, m, q;
const int MM = 1e6+2;
const int MN = 5005;
int dif[MN*MN];
void solve(){
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int lo = i*j, hi = n*m-(n-i+1)*(m-j+1)+1;
            dif[lo]++; dif[hi+1]--;
        }
    }
    dif[0]=0;
    for(int i=1;i<=n*m;i++){
        dif[i] = dif[i-1]+dif[i];
    }
    for(int i=1, num; i<=q;i++){
        scanf("%d", &num);
        printf("%d\n", dif[num]);
    }




}
int main(){
    solve();
    return 0;
}