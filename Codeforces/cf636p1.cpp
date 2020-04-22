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
    while(T--){
        int N; scanf("%d", &N);
        int i=3, po=2;
        while(true){
            if(N%i==0){
                printf("%d\n", N/i);
                break;
            }
            i += pow(2, po);
            po++;
        }
    }
    return 0;

}