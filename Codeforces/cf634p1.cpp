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
#include <climits>
using namespace std;
typedef long long ll;
int main(){
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        ll N; cin >> N;
        if(N%2) printf("%lld\n", N/2);
        else printf("%lld\n", N/2-1);
    }
    return 0;

}