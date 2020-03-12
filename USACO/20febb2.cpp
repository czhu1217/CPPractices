
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
int n;
string s, t;
int main(){
    cin >> n;
    cin >> s >> t;
    int cnt = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            cnt++;
        }
        else if(cnt!=0){
            cnt = 0;
            ans++;
        }

    }
    cout << ans << endl;
    return 0;
    
}