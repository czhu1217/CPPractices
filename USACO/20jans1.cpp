#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int N, K, a[1002], tmp, rem[1003], mm=0, ans;
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        scanf("%d", &a[i]);
        mm = max(mm, a[i]);
    }
    for(int i=1;i<=mm;i++){
        int num = 0;
        tmp = 0;
        for(int j=1;j<=N;j++){
            num += a[j]/i;
        }
        if(num<(K/2)){
            // cout << "?" << "\n";
            break;
        }
        else if(num>K){
            ans = max(ans, i*K/2);
        }
        else{
            for(int j=1;j<=N;j++){
                rem[j] = a[j]%i;
            }
            sort(rem+1, rem+N+1);
            reverse(rem+1, rem+N+1);
            tmp = (num-K/2)*i;
            for(int j=1 ;j<=K-num;j++){
                tmp += rem[j];

            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";
    return 0;



}