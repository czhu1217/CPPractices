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
int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        ll sum1=0, sum2=0;
        int i=1;
        for(;i<N/2;i++){
            sum1 += pow(2, i);
        }
        sum1 += pow(2, N);
        for(;i<N;i++){
            sum2 += pow(2, i);
        }
        cout << abs(sum1-sum2) << "\n";
    }
    return 0;
}