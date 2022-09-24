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
int mat[101][101];
int n, m;
bool che(int i, int j){
    if(i<=0||j<=0||i>n||j>m) return 0;
    if(mat[i][j]==0) return 0;
    if(mat[i][j]==-1) return 1;
    return 0;

}
bool check(int i, int j, int val){
    return (che(i+1, j)+che(i+1, j+1)+che(i, j+1)+che(i-1, j)+che(i, j-1)+che(i-1, j-1)+che(i+1, j-1)+che(i-1, j+1)) == val;
}
int main(){
    cin >> n >> m;
    char c;
    FOR(i, 1, n){
        FOR(j, 1, m){
            cin >> c;
            if(c=='.'){
                mat[i][j] = 0;
            }
            else if(c=='*'){
                mat[i][j] = -1;
            }
            else mat[i][j] = c-'0';
        }
    }
    // FOR(i, 1, n){
    //     FOR(j, 1, m) cout << mat[i][j] << " ";
    //     cout << "\n";
    // }
    FOR(i, 1, n){
        FOR(j, 1, m){
            if(mat[i][j]==-1) continue;
            if(!check(i, j, mat[i][j])){
                // cout << i << " " << j << "\n";
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}