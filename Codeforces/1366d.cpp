
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
const int MM = 5e5+1;
map<int, int> fac;
void sieve(int a){
    while(a%2==0){
        fac[2]++;
        a /= 2;
    }
    for(int i=3;i<=sqrt(a);i++){
        while(a%i==0){
            fac[i]++;
            a = a/i;
        }
    }
}
int done[MM];
void solve(){
    int n; int a; int res[MM][3];
    cin >> n;
    for(int k=1;k<=n;k++){
        fac.clear();
        cin >> a;
        sieve(a);
        if(fac.size()<=1){
           res[k][1]=-1;
           res[k][2] = -1;
           continue;
        }
    
    if(a%2==0){
        for(int j=0;j<=fac[2];j++){
            if(done[k])break;
            for(auto e:fac){
                if(e.f!=2){
                    int temp = pow(2, j);
                    if((int)__gcd(temp+e.f, a)==1){
                        done[k] = true;
                        res[k][0] = temp; res[k][1] = e.f;

                    }
                }
            }
        }
    }
    }

}
int main(){
    solve();
    return 0;
}