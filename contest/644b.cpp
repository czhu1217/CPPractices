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
int a[50005], n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int mi=INT_MAX, id;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]<mi){
            mi = a[i]-a[i-1];
            id = i;
        }
    }
    cout << mi << "\n";


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}