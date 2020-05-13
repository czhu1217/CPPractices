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
int N, K;
int main(){
    int T; cin >> T;
    while(T--){
        cin >> N >> K;
        if(N%2==0){
            N += 2*K;
        }
        else{
            int div=N;
            for(int i=2;i<=sqrt(N);i++){
                if(N%i==0){div=i;break;}
            }
            N += div+2*(K-1);
        }
        cout << N << "\n";

    }
    return 0;

}