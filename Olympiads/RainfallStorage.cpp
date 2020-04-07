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
int N, a[1000005], mx=0;
ll tot=0;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        if(a[i]<=mx){
            for(int j=i-1;j>0;j--){
                if(a[j]>=a[i]) break;
                tot += a[i]-a[j];
                a[j]=a[i];
            }
        }
        else{
            for(int j=i-1;j>0;j--){
                if(a[j]>=mx) break;
                tot += mx-a[j];
                a[j]=mx;
            }
            mx = a[i];
        }
    }
    cout << tot << "\n";
    return 0;
}