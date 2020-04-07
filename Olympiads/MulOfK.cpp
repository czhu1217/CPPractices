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
const int MM = 1e6+2;
typedef long long ll;
int N, K, a[MM]; ll pre[MM];
vector<int> r[MM];
int ans=0;
int main(){
    pre[0]=0;
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        pre[i] = a[i]+pre[i-1];

    }
    for(int i=N;i>0;i--){
        for(int j=0;j+i<=N;j++){
            if((pre[j+i]-pre[j])%K==0){
                cout << i << "\n";
                return 0;
            }
        }
    }
    cout << "-1" << "\n";
    return 0;

}