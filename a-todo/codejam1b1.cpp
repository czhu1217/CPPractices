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
#include <iostream>
using namespace std;
typedef long long ll;
void bin(unsigned n) 
{ 
    if (n > 1) 
        bin(n/2); 
  
    cout << n % 2; 
} 
int main(){
    int T; cin >> T;
    for(int t=1;t<=T;t++){
        int orix, oriy;
        bool done = 0, not1=0, not2=0, not3=0;
        int x, y; scanf("%d %d", &x, &y);
        if(!((x%2)^(y%2))){
            printf("Case #%d: IMPOSSIBLE\n", t);
            continue;
        }
        orix = x; oriy = y;
        x = abs(x); y = abs(y);
        int nx = -1*x, ny = -1*y;
        for(int i=0;i<32;i++){
            if((i)>(log2(x)+1)){
                nx = nx^(1<<i);
            }
        }
        for(int i=0;i<32;i++){
            if((i)>log(y)+1){
                ny = ny^(1<<i);
            }
        }
        int ans1 = x^y;
        for(int i=0; i<=max(log2(x), log2(y)); i++){
            if((ans1&(1<<i))==0){ not1=1;ans1 = INT_MAX;break;}
        }
        int ans2 = x^ny;
        bool hz=0;
        for(int i=0;i<=max(log2(x), log2(y)+1);i++){
            if(i>log2(y)+1){
                if(hz&&((ans2&(1<<i))==0)){not2=1; ans2 = INT_MAX;break;}
                if((ans2&(1<<i))==1)hz=1;
                continue;
            }
            if((ans2&(1<<i))==0){not2=1; ans2 = INT_MAX;break;}
        }
        int ans3 = nx^y;
        hz = 0;


        for(int i=0;i<=(max(log2(y), log2(x)+1));i++){
            if(i>log2(x)+1){
                if(hz&&((ans3&(1<<i))==0)){not3=1; ans3 = INT_MAX;break;}
                if((ans3&(1<<i))==1)hz=1;
                continue;
            }
            if((ans3&(1<<i))==0){not3=1;ans3=INT_MAX;break;}
        }
        int ans4 = nx^ny;
        bool not4 = 0;
        for(int i=0;i<=max(log2(x)+1, log2(y)+1);i++){
            if((ans4&(1<<i))==0){not4=1;ans4=INT_MAX;break;}
        }
        int mi = min(ans1, min(ans2, min(ans3, ans4)));
        printf("Case #%d: ", t);
        if((!not1)){
            for(int i=0;i<=max(log2(x), log2(y)); i++){
                if(((1<<i)&x)){
                    if(orix>0)
                    printf("E");
                    else printf("W");
                }
                else {
                    if(oriy>0)printf("N");
                    else printf("S");
                }
            }

        }
        else if((!not2)){
            for(int i=0;i<=max(floor(log2(x)), floor(log2(y)+1));i++){
                if((1<<i)&x){
                    if(orix>0)
                    printf("E");
                    else printf("W");
                }
                else if((1<<(i+1))&x){
                    if(oriy>0) printf("S");
                    else printf("N");
                }
                else if((1<<i)<=log2(y)){
                    if(oriy>0)
                    printf("S");
                    else printf("N");
                } 
            }
        }
        else if((!not3)){
            for(int i=0;i<=max(log2(y), log2(x)+1);i++){
                if((1<<i)&y){
                    if(oriy>0)
                    printf("N");
                    else printf("S");
                }
                else if((1<<i)>x){
                    if(orix>0)
                    printf("E");
                    else printf("W");
                }
                else{
                    if(orix>0)
                     printf("W");
                    else printf("E");
                }
            }
        }
        else if((!not4)){
            for(int i=0;i<=max(log(y)+1, log(x)+1);i++){
                if((1<<i)&nx){
                    if((1>>i)>x){
                        if(orix>0)printf("W");
                        else printf("E");
                    }
                    else{
                        if(orix>0) printf("E"); else printf("W");
                    }
                }
                else{
                    if((1>>i)>y){
                        if(oriy>0)printf("S");
                        else printf("N");
                    }
                    else{
                        if(oriy>0)printf("N");
                        else printf("S");
                    }
                }
            }
        }
        else{
            printf("IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;

    
}