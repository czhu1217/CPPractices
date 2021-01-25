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
void solve(){
    int ans=0;
    bool can[30];
    string st; cin >> st;
    for(int i=0;i<st.size()-1;i++){
        memset(can, 1, sizeof can);
        if(st[i]==st[i+2]){//it is a palindrome
            // cout << "a " << i << "\n";
            ans++;
            can[st[i]-'a'] = 0;
            can[st[i+1]-'a'] = 0;
            if(i+3<st.size()) can[st[i+3]-'a'] = 0;
            if(i+4<st.size()) can[st[i+4]-'a'] = 0;
            for(int j=0;j<26;j++){
                if(can[j]){
                    st[i+2] = 'a'+j;
                    break;
                }
            }
            // cout << st << "\n";
        }
        memset(can, 1, sizeof can);
        if(st[i]==st[i+1]){
            // cout << "b " << i << "\n";
            ans++;
            can[st[i]-'a'] = 0;
            can[st[i+2]-'a'] = 0;
            if(i-1>=0)can[st[i-1]-'a'] = 0;
            if(i+3<st.size())can[st[i+3]-'a'] = 0;
            for(int j=0;j<26;j++){
                if(can[j]){
                    st[i+1] = 'a'+j;
                    break;
                }
            }
            // cout << st << "\n";

        }
    }
    cout << ans << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}