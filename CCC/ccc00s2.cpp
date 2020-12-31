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
int n; double stream[102];
int main(){
    scanf("%d", &n);
    FOR(i, 1, n) cin >> stream[i];
    int q;
    cin>>q; int a, b;
    while(q!=77){
        if(q==99){
            int k, p;
            scanf("%d %d", &k ,&p);
            double t = stream[k];
            stream[k] = t*p/100.0;
            for(int i=n; i>k; i--){
                stream[i+1] = stream[i];
            }
            stream[k+1] = t-t*p/100.0;
            n++;

        }
        if(q==88){
            int k; scanf("%d", &k);
            stream[k] = stream[k]+stream[k+1];
            n--;
            for(int i=k+1; i<=n;i++){
                stream[i] = stream[i+1];
            }
        }
        cin >> q;
    }
    FOR(i, 1, n) cout << stream[i] << " ";
    

    return 0;
}