
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
    int x, y, z; cin >> x >> y >> z;

    int a, b, c;
    if(x==y&&z<=x){
        a = x;
        b = z;
        c = 1;
    }
    else if(x==z&&y<=z){
        b = x;
        a = y;
        c = 1;
    }
    else if(y==z&&x<=y){
        c = y;
        a = x;
        b = 1;
    }
    else{
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    printf("%d %d %d\n", a, b, c);
}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}