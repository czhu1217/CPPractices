#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<ll, ll> pi;
#define FOR(i, a, b) for (ll i=a; i<=(b); i++)
#define pb push_back
#define f first
#define s second
string s;
const ll MM = 1e4+5;
ll l[MM], o[MM], v[MM], e[MM], lo[MM], ov[MM], ve[MM], lov[MM], ove[MM], love[MM];
int main(){
    cin >> s;
    FOR(i, 0, s.size()-1){
        if(i){
            l[i] = l[i-1];
            o[i] = o[i-1];
            v[i] = v[i-1];
            e[i] = e[i-1];
        }
        if(s[i]=='l'){
            l[i]++;
        }
        if(s[i]=='o') o[i]++;
        if(s[i]=='v') v[i]++;
        if(s[i]=='e') e[i]++;
    }
    FOR(i, 0, s.size()-1){
        if(i==0) continue;
        else{
            if(i>1){
                lo[i] = lo[i-1];
                ov[i] = ov[i-1];
                ve[i] = ve[i-1];
            }
            if(s[i]=='o') lo[i] += l[i-1];
            if(s[i]=='v') ov[i] += o[i-1];
            if(s[i]=='e') ve[i] += v[i-1];
        }

    }
    FOR(i, 1, s.size()-1){
        if(i<2)continue;
        else{
            if(i>2){
                lov[i] = lov[i-1];
                ove[i] = ove[i-1];
            }
            if(s[i]=='v') lov[i] += lo[i-1];
            if(s[i]=='e') ove[i] += ov[i-1];
        }
    }
    FOR(i, 1, s.size()-1){
        if(i<3) continue;
        else{
            if(i>3){
                love[i] = love[i-1];
            }
            if(s[i]=='e'){
                love[i] += lov[i-1];
            }

        }
    }
    cout << love[s.size()-1] << "\n";

    return 0;
}