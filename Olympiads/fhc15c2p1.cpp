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
const int MM = 5e4+5;
int t, n; int c = 1;
void solve(){
    deque<int> a, b, ai, bi;
    printf("Case #%d: ", c++);
    int cnt=0;
    scanf("%d", &n);
    int x;
    FOR(i, 1, n){
        scanf("%d", &x); a.pb(x);
        ai.pb(x);
    }
    FOR(i, 1, n){
        if(b.empty()){
            b.push_back(a.back()); a.pop_back();
        }
        else if(a.back()+1==b.front()){
            b.push_front(a.back()); a.pop_back();
        }
        else if(a.back()-1==b.back()){
            b.push_back(a.back()); a.pop_back();
        }
        else if(a.front()+1==b.front()){
            b.push_front(a.front()); a.pop_front();
        }
        else if(a.front()-1==b.back()){
            b.pb(a.front()); a.pop_front();
        }
    }
    if(b.size()==n){ printf("yes\n"); return;}
    a = ai; b = bi;
        FOR(i, 1, n){
        if(b.empty()){
            b.push_back(a.front()); a.pop_front();
        }
        else if(a.back()+1==b.front()){
            b.push_front(a.back()); a.pop_back();
        }
        else if(a.back()-1==b.back()){
            b.push_back(a.back()); a.pop_back();
        }
        else if(a.front()+1==b.front()){
            b.push_front(a.front()); a.pop_front();
        }
        else if(a.front()-1==b.back()){
            b.pb(a.front()); a.pop_front();
        }
    }
     if(b.size()==n){ printf("yes\n"); return;}
     printf("no\n");
    

}
int main(){
    // freopen("lazy_sort_input.txt","r", stdin);
    // freopen("lazysort.txt", "w", stdout);
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}