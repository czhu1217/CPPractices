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
int T, B;
int a[102];
int main(){
    cin >> T >> B;
    for(int t=1;t<=T;t++){
        for(int i=1;i<=B;i++){
            printf("%d", i);
            fflush(stdout);
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=B;i++){
        printf("%d", a[i]);
        }
        fflush(stdout);
        char ok;
        scanf("%d", &ok);
    }

    
    return 0;


}