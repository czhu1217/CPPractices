
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, base = 131, ans;
ll p[MM] = {1}, pre, suf;
unordered_map<ll, int> mp; string s;
int main(){
    for(int i=1;i<MM;i++){
        p[i] = p[i-1]*base;
    }
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> s; int m = s.size(), best = 0;
        pre = suf = 0;
        for(int j=0; j<s.size(); j++){
            pre = pre*base + s[j]; suf = suf+s[m-j-1]*p[j];
            if(pre==suf) best = max(best, mp[pre]);

        }
        ans = max(ans, best+1);
        mp[pre] = best+1;
    }
    cout << ans << "\n";

}
