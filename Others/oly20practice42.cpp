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
#include <climits>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int n, a[MM];
int main(){
    ll ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i=3;i<=n;i+=2){
        ans += pow(a[i]-a[i-2], 2);
    }
    if(n%2==0){
        ans += pow(a[n]-a[n-1], 2);
        for(int i=n-2;i>0;i-=2){
            ans += pow(a[i]-a[i+2], 2);
        }
        ans += pow( a[2]-a[1], 2);
    }
    else{
        ans += pow(a[n]-a[n-1], 2);

        for(int i=n-3;i>0;i-=2){
            ans += pow(a[i]-a[i+2], 2);
        }
        ans += pow(a[2]-a[1], 2);
        
    }
    cout << ans << "\n";
    return 0;
    


}