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
int T;
vector<int> fac;
int a[102][102];
void findFac(int x){
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            fac.push_back(i);
            fac.push_back(x/i);
        }
    }
}
int main(){

    cin >> T;
    for(int t=1;t<=T;t++){
        fac.clear();
        printf("Case #%d: ", t);
        int N, K;
        cin >> N >> K;
        for(auto e:fac){
            for(int i=1;i<=N;i++){
                a[1][1] = i;
                for(int j=2;j<=N;j++){
                    a[j][j] = j-e*(j-1)
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }

    }
    return 0;
}