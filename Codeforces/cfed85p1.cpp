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
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        bool flg = 1;
        pair<int, int> pi[102];
        int N, pre1=0, pre2=0;
        scanf("%d", &N);
        for(int i=1;i<=N;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if(a<pre1||b<pre2){
                flg=0;
            }
            else if(b-pre2>a-pre1){ flg=0;}
            pre1=a;pre2=b;

        }
        if(flg)printf("YES\n");
        else printf("NO\n");

    }
    return 0;
    
}