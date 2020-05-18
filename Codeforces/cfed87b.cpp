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
void solve(){
    string s; cin >> s; int cnt[4] = {0,0,0,0};

    int mi = INT_MAX;
    int l=0, r=0;
    for(;r<s.size();r++){
        if(s[r]=='1')cnt[1]++;
        if(s[r]=='2')cnt[2]++;
        if(s[r]=='3')cnt[3]++;
        while(cnt[1]&&cnt[2]&&cnt[3]){
            mi = min(mi, r-l+1);
            if(s[l]=='1')cnt[1]--;
            if(s[l]=='2')cnt[2]--;
            if(s[l]=='3')cnt[3]--;
            l++;
        }
    }
    if(mi==INT_MAX)mi=0;
    cout << mi << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}