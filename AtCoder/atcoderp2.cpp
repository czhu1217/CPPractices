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
    ll N;
    cin >> N;
    ll sum=0;
    for(ll i=1;i<=N;i++){
        if((i%3)!=0&&(i%5)!=0) sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}