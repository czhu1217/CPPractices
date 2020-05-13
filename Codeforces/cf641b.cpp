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
int n; int a[100005], ans[100005];int final=0;
void solve(){
    final=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        ans[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j*i<=n;j++){
            if(a[i*j]>a[i]){
                ans[i*j] = max(ans[i*j], ans[i]+1);
                final = max(final, ans[i*j]);
            }
        }
    }
    cout << final << "\n";
    


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}