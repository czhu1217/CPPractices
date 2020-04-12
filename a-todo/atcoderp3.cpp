#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main(){
    int k;cin >> k;
    ll sum=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int t=1;t<=k;t++){
                sum += __gcd(i, __gcd(j, t));
            }
            
        }
    }
    cout << sum << endl;
    return 0;
}