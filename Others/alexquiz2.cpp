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
const int MM = 1e5+5;
bool p[MM]; vector<int> v;
ll sum[MM], q;
void sieve(){
    memset(p, 1, sizeof p);
    p[0]=p[1]=0; sum[0]=sum[1] = 0;
    for(int i=2;i<MM;i++){
        sum[i] = sum[i-1];
        if(p[i]){
            v.push_back(i);
            sum[i] += i;

        }
        for(int e:v){
            if(i*e>=MM)break; //out of the range
            p[i*e]=0; // i*e is not a prime number

        }
    }
}
int main(){
    sieve();
    cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        cout <<  sum[b] - sum[a-1] << "\n";
    }
    return 0;
}