#include <bits/stdc++.h>
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
const int MM = 1005;
int n;
int a[MM], b[MM]; char c; int lo = 0, hi = -1;
int main(){
    cin >> n; int lv = 0;
    FOR(i, 1, n){
        cin >> c;
        if(c=='v'){
             lv--;
             lo = min(lo, lv);
             hi = max(lv, hi);
             a[i] = lv;
             b[i] = 2;
        }
        else if(c=='^'){
            a[i] = lv;
            b[i] = 1;
            hi = max(hi, lv);
            lv++;
        }
        else{
            lo = min(lo, lv);
             hi = max(lv, hi);
            a[i] = lv;
            b[i] = 3;
        }
    }
    // cout << lo << " " << hi << "\n";
    // FOR(i, 1, n) cout << a[i] << " ";
    // cout << "\n";
    for(int i=hi;i>=lo;i--){
        for(int j=1;j<=n;j++){
            if(a[j]!=i){
                cout << '.';
                continue;
            }
            if(b[j]==1){
                cout << "/";
            }
            else if(b[j]==2){
                cout << "\\";
            }
            else{
                cout << "_";
            }
        }
        cout << "\n";
    }

    return 0;
}