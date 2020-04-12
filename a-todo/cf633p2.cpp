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
int a[100005];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int N;scanf("%d", &N);
        int b[100005];
        for(int i=1;i<=N;i++){
            scanf("%d", &b[i]);
        }
        sort(b+1, b+N+1);
        int mid= N%2?N/2+1:N/2;int lo=mid, hi=mid;
        if(N%2==0)hi++; else{printf("%d ", b[mid]); lo--;hi++;}
        if(N%2==0){
            while(lo>0&&hi<=N){
                printf("%d %d ", b[lo], b[hi]);
                lo--;hi++;
            }
        }
        else{
            if(b[mid]-b[lo]>b[hi]-b[mid]){
                while(lo>0&&hi<=N){
                    printf("%d %d ", b[hi], b[lo]);
                    lo--;hi++;
                }
            }
            else{
                while(lo>0&&hi<=N){
                    printf("%d %d ", b[lo], b[hi]);
                    lo--;hi++;

                }
            }
        }
        printf("\n");
        

    }
    return 0;
}