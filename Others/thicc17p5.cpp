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
int n, k, a[1000001], f[1000001], cnt=0;
ll ans=0, head=1;
int main(){
    cin >> n >> k;
    memset(f, 0, sizeof(f));
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(!f[a[i]]){
            cnt++;
        }
        f[a[i]]++;
        while(cnt>=k){
            ans += n-i+1;
            f[a[head]]--;
            if(!f[a[head]]) cnt--;
            head++;
        }

    }
    cout << ans << "\n";
    return 0;

}