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
using namespace std;
typedef long long ll;
int main(){
    int T; cin >> T;
    while(T--){
        int x, n, m;
        scanf("%d %d %d", &x, &n, &m);
        while(x-(floor(x/2)+10)>=10&&n>0){
            x = floor(x/2)+10;
            n--;
        }
        if(x<=10*m){
            printf("YES\n");
        }
        else{
            while(n>0&&floor(x/2)+10<x){
                x = floor(x/2)+10;
                n--;
            }
            if(x<=10*m) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}