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
int main(){
    int T; int r, c;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d %d", &r, &c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(i<=ceil(r/2)&&j<c){
                    printf("W");
                }
                else printf("B");
            }
            printf("\n");
        }
    }
    return 0;
}