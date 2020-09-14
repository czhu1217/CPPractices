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
string t, p;
int n, m, ans;
int b[1000010];
void kmpPre(){
    int i=0,j=-1; b[0] = -1;
    while(i<p.size()){
        while(j>=0&&p[i]!=p[j])j = b[j];
        i++;j++;
        b[i]=j;
    }

}
void kmpSearch(){
    int i=0,j=0;
    while(i<t.size()){
        while(j>=0&&t[i]!=p[j])j = b[j];
        i++;j++;
        if(j==p.size()){
            ans++;
            j = b[j];
        }
    }
}
int main(){
    cin >> t >> p;
    kmpPre(); kmpSearch();
    cout << ans << "\n";
    return 0;
}