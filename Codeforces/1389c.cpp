
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
int cnt[11];
void solve(){
    int ans = INT_MAX;
    string a; cin>> a;
    memset(cnt, 0, sizeof cnt);
    ans = a.size()-2;
    for(int i=0;i<10;i++){
        
        for(int j=0;j<10;j++){
            bool first = 1; int cnt =0;
            for(int k=0;k<a.size();k++){
                if(first&&a[k]-'0'==i){
                    cnt++; first=0;
                }
                else if((!first)&&a[k]-'0'==j){
                    cnt++; first=1;
                }
            }  
            if(cnt%2&&i!=j)cnt--;
            ans = min(ans, (int)a.size()-cnt);

        }
    }
        cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}