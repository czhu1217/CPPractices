
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
string s1, s2;
void solve(){
    s1 = "Ashishgup"; s2 = "FastestFinger";
    int n; cin >> n;
    if(n==1){cout << s2 << "\n"; return;}
    if(n==2){ cout << s1 << "\n"; return;}
    int cnt=0;
    while(n%2==0){
        cnt++;
        n /= 2;
    }
    map<int, int> m;
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            m[i]++;
            n /= i;
        }
    }
    if(n>2) m[n]++;
    int cnt2 = 0;
    for(auto e:m){
        cnt2 += e.s;
    }
    if(cnt==1){
        if(cnt2>1){cout << s1 << "\n"; return;}
        else cout << s2 << "\n";
    }
    else{
        if(cnt2>=1) cout << s1 << "\n";
        else cout << s2 << "\n";

    }

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}