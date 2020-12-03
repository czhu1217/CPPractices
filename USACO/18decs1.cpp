//AC
//binary search
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
int n, m , c;
const int MM = 1e5+5;int cnt;
int a[MM];
bool test(int k){
    int sum = 0; int rem = m;
    for(int i=1;i<=n;i++){
        cnt++;
        if(i!=n&&sum + a[i+1]-a[i]<=k&&cnt<c) {
            sum += a[i+1]-a[i];
            continue;
        }
        else{
            rem--;
            sum = 0;
            cnt = 0;
        }
        if(rem<0) return false;
    }
    return true;
}
int main(){
    ifstream cin("convention.in");
    ofstream cout("convention.out");
    cin >> n >> m >> c;
    FOR(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    int lo = 0, hi = 1e9;
    while(lo!=hi){
        int mid = (lo+hi)/2;
        if(test(mid)) hi = mid;
        else lo = mid+1;

    }
    cout << lo << "\n";


    return 0;
}
