#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int idk[100005], t, W, N, s, cur;
int main(){
    cin >> W >> N;
    memset(idk, 0, sizeof(idk));
    for(int i=1;i<=N;i++){
        cin >> t;
        idk[i] = t;
        cur = cur + t - idk[max(0, i-4)];
        if(cur>W){
            cout << i-1;
            return 0;
        }
        
    }
    cout << N;
    return 0;
}