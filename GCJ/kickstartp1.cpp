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
    for(int t=1;t<=T;t++){
        int ans = 0;
        int N; cin >> N;
        int a[105];
        for(int i=1;i<=N;i++){
            scanf("%d", &a[i]);

        }
        for(int i=2;i<N;i++){
            if(a[i]>a[i-1]&&a[i]>a[i+1])
            ans++;
        }
        printf("Case #%d: %d\n", t, ans);

    }
    return 0;
}