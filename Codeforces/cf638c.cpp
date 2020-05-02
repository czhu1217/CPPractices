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
const int MM = 1e5+5;
int N, K;  string ans[MM];
int main(){
    int T; cin >> T;
    while(T--){
         cin >> N >> K;
    vector<char> v; string ans;
    string s; cin >> s; 
    sort(s.begin(), s.end());
    int cnt=1;char test = s[0]; int idx;
    for(int i=1;i<s.size();i++){
        if(s[i]!=test){if(cnt==1)idx = i;cnt++;test=s[i];}
    }
     if(cnt==1){
        int len = N/K;
        if(N%K!=0)len++;
        for(int i=1;i<=len;i++){
            ans += test;
        }
        cout << ans << "\n";
    }
    else if(idx<K){
        cout << s[K-1] << "\n";
    }

    else if(cnt==2&&idx==K){
        int len = N/K;
        if(N%K!=0)len++;
        ans = s[0];
        for(int i=1;i<len;i++){
            ans += test;
        }
        cout << ans << "\n";

    }

    else{
        ans=s.substr(K-1);
        cout << ans << "\n";
    }
    
    }
    return 0;
}