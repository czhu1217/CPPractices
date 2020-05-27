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
int n, a[55];
void solve(){
    int od=0, ev=0;
vector<int> odd, even;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]%2){od++; odd.push_back(a[i]);}
        else{ev++;even.push_back(a[i]);}
    }
    if((od%2==0)&&(ev%2==0)){
        cout << "YES\n";
        return;
    }
    // sort(odd.begin(),odd.end());
    // sort(even.begin(),even.end());
    for(int i=0;i<odd.size();i++){
        for(int j=0;j<even.size();j++){
            if(abs(odd[i]-even[j])==1){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
    


}
int main(){
    int t; cin >> t;
    while(t--)solve();
    return 0;
}