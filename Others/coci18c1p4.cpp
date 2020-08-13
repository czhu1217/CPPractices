
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
#include <stack>
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
int n, m, h[2005];
bool a[2005][2005];
char c;
stack<pi> st;
ll ans=0; int idx;
ll calc(int x){
    return 1LL*(x+1)*x/2;
}
int main(){
    memset(a, 0, sizeof a);
    cin >> n >> m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> c;
            if(c=='#') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    FOR(i, 1, n){
        // printf("i %d\n", i);
        FOR(j, 1, m+1){
            idx = j;
            if(a[i][j]) h[j]++;
            else h[j]=0;
            cout << h[j] << " ";
            while((!st.empty())&&(h[j]<st.top().f)){
                pi tmp = st.top(); st.pop();
                idx = tmp.s;
                ans += calc(tmp.f)*calc(j-tmp.s);
            // printf("%d %d %d %d\n", i, j, h[j], ans);

            }
            if((j<=m))
            st.push({h[j], idx});
            // printf("%d %d\n", j, ans);
        }
        cout << "\n";
        
    }
    cout << ans << "\n";
    return 0;
}