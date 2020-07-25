
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
int a[102];
void solve(){
    int n; cin >> n;
    FOR(i, 1, n) cin >> a[i];
    char ans[102][102];
    for(int i=1;i<=100;i++){
        ans[0][i] = 'a';
    }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=100;j++){
           if(a[i]>=j)ans[i][j] = ans[i-1][j];
           else{
               if(ans[i-1][j]=='a')ans[i][j] = 'b';
               else ans[i][j] = 'a';
           }
       }

   }
    for(int i=0;i<=n;i++){
        for(int j=1;j<=100;j++)cout << ans[i][j];
        cout << "\n";

    }

}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}