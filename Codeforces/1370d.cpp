
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
    int a[MM], k, n;
bool check(int x, int id){
    int len = 0;

    for(int i=1;i<=n;i++){
        if(id==0){len++;id = 1;}
        else{
            if(a[i]<=x){len++; id = 0;}
        }
    }
    return len>=k;
}
void solve(){

cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    int lo=1, hi = 1e9;

    while(lo<hi){
        int mid = (lo+hi)/2;
        if(check(mid, 0)||check(mid, 1)){
            hi = mid;
        }
        else lo = mid+1;
    }
    cout << lo << "\n";


}
int main(){
    solve();
    return 0;
}