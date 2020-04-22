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
using namespace std;
typedef long long ll;
ll MM = 1e9;

int main()
{
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++)
    {
        vector<ll> ve;
        int ans1 =1, ans2 = 1;
        printf("Case #%lld: ", t);
        string s; cin >> s; ll mul=1, pre=1, v=0, h=0;
        for(ll i=0;i<s.size();i++){
            if(s[i]>'1'&&s[i]<='9'){
                mul *= s[i]-'0';
                ve.push_back(s[i]-'0');
            }
            if(s[i]=='N') v -= mul;
            if(s[i]=='S') v+=mul;
            if(s[i]=='W')h -= mul;
            if(s[i]=='E')h+=mul;
            if(s[i]==')'){ if(!ve.empty()) mul /= ve.back();ve.pop_back();}
            v = (v+MM)%MM;
            h = (h+MM)%MM;

        }


        
        printf("%lld %lld\n", 1+h, 1+v);
        
    }
    return 0;
}