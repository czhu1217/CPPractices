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
    for(int t=1;t<=T;t++){
        int N; cin >> N; int a, b; cin >> a >> b;
        int sum=0;
        while(sum<N){
            int cnt=0;
            for(int i=1;i<=a;i++){
                if(sum>=N)break;
                sum++;
                if(i<b){
                    printf("%c", 'a'+i-1);
                }
                else printf("%c", 'a'+b-1);
            }
            
        }
        printf("\n");

    
    }
    return 0;
}