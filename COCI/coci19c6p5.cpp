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
#include <stack>
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
int n, k;
ll ans=0;
const ll mod = 1e9+7;
map<string, ll> m;
int main(){
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            string s; cin >> s;
            if(i==1) m[s]++;
            else{ m[s] = (m[s]+m[s.substr(0, s.size()-1)]);
            m[s] =( m[s]+m[s.substr(1, s.size()-1)]);
            }

            if(i==n) ans = (ans + m[s]);

        }
    }

    cout << ans << "\n";

    return 0;
}