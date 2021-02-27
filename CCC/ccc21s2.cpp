#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int, int> pi;
#define FOR(i, a, b) for (int i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
const int MM = 5e6+5;
int n, m, k, x;
bool r[MM], c[MM];
char ch;
int ans;
int main(){
    cin >> m >> n >> k;
    FOR(i, 1, k){
        cin >> ch >> x;
        if(ch=='R'){
            r[x] = !r[x];
        }
        else{
            c[x]=!c[x];
        }
    }
    FOR(i, 1, m){
        FOR(j, 1, n){
            if(r[i]^c[j]){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}