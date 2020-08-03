
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
const int MM = 1e5+5;
int id[MM], n, temp[MM]; string a[MM];
int main(){
    string ans;
    memset(id, 0, sizeof id);
    cin >> n;
    for(int i=1;i<=n;i++){
        string x; cin >> x;
        a[i] = x;
    }
    for(int i=25;i>=0;i--){
        bool pos=1;
        for(int j=1;j<=n;j++){
            bool found = 0;
            for(int k=id[j];k<a[j].size();k++){
                if(a[j][k]-'a'==i){ 
                    temp[j] = k;
                    found=1; break;
                }
            }
            if(!found){pos=0; break;}
        }
        if(pos){
            for(int j=1;j<=n;j++){
                id[j] = temp[j]+1;
            }
            ans += (char)'a'+i;
            i++;

        }
    }
    if(ans.size()==0)cout << -1 << '\n';
    else
    cout << ans << "\n";

    return 0;
}