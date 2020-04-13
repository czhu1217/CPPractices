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
        int sud[12][12]; memset(sud, 0, sizeof(sud));
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                char c;
                scanf(" %c", &c);
                sud[i][j] = c-'0';
            }
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(sud[1+3*(i-1)+j-1][i+3*(j-1)]==1){
                    sud[1+3*(i-1)+j-1][i+3*(j-1)] = 2;
                }
                else sud[1+3*(i-1)+j-1][i+3*(j-1)]=1;
            }
        }
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                printf("%d", sud[i][j]);
            }
            printf("\n");
        }
    }
    

    return 0;
}