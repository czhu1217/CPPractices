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
const int MM = 1000;
int k, a[105], n, cnt=0;
bool p[1000]; 
vector<int> v;
void sieve(){
    memset(p, 1, sizeof p);
    p[0]=p[1]=0; 
    for(int i=2;i<MM;i++){
        if(v.size()>100) break;
        if(p[i]){
            v.push_back(i);

        }
        for(int e:v){
            if(i*e>=MM)break; //out of the range
            p[i*e]=0; // i*e is not a prime number

        }
    }
}
int main(){
    sieve();
    cin >> k;
    int n;
    for(int i=1;i<=100;i++){
        if(i*(i+1)>=2*k){
            n=i;break;
        }
    }
    int t = n*(n+1)/2;
    t = t-k;
    FOR(i, 1, t){
        a[i] = v[i-1];
    }
    FOR(i, t+1, n) a[i] = 1;
    cout << n << "\n";
    FOR(i, 1,n) cout << a[i] << " ";
    cout << "\n";


    return 0;
}