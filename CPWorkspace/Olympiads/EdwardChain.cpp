#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int N;
const int mx = 1e6+2;
char a[mx], preg[mx], pres[mx], sufg[mx], sufs[mx];
long long ans = 0;
int main(){
    scanf("%d", &N);
    string a;
    preg[0]=0;pres[0]=0;sufs[0]=0;sufg[0]=0;sufg[N+1]=0;sufs[N+1]=0;
    cin >> a;
    for(int i=1;i<=N;i++){

        if(a[i-1]=='g'){
            // printf("1");
            preg[i] = preg[i-1]+1;
            pres[i] = 0;
        } 
        else if(a[i-1]=='s'){
            // printf("2");
            pres[i] = pres[i-1]+1;
            preg[i] = 0;
        }
        else{
            // printf("3");
            pres[i] = pres[i-1]+1;
            preg[i] = preg[i-1]+1;
        }
    }
    // for(int i=1;i<=N;i++){
    //     printf("%d ", pres[i]);

    // }
    // printf("\n");
    // for(int i=1;i<=N;i++){
    //     printf("%d ", preg[i]);

    // }
    // printf("\n");

    for(int i=N;i>0;i--){
        if(a[i-1]=='g'){
            sufg[i] = sufg[i+1]+1;
            sufs[i] = 0;
        } 
        else if(a[i-1]=='s'){
            sufs[i] = sufs[i+1]+1;
            sufg[i] = 0;
        }
        else{
            sufs[i] = sufs[i+1]+1;
            sufg[i] = sufg[i+1]+1;
        }
        if(max(preg[i-1], pres[i-1])+max(sufg[i], sufs[i])>ans)ans = max(preg[i-1], pres[i-1])+max(sufg[i], sufs[i]);
    }
    //     for(int i=1;i<=N;i++){
    //     printf("%d ", sufs[i]);

    // }
    // printf("\n");
    // for(int i=1;i<=N;i++){
    //     printf("%d ", sufg[i]);

    // }

    printf("%lld\n", ans);

    
    return 0;

}