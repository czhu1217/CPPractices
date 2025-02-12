
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
    int a[100005];bool win[100005];
#define ins insert
void solve(){
    int n; cin >> n;
    FOR(i, 1, n)cin >> a[i];
    
    int cnt = 0;
    win[n] = 1;
    for(int i=n-1;i>0;i--){
        if(a[i]==1){
            if(win[i+1]) win[i] = 0;
            else win[i] = 1;
        }
        else{
            win[i] = 1;
        }

    }
    if(win[1])cout << "First\n";
    else cout << "Second\n";
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}