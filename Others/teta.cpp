#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int k, pr[21], x, combo[4], t, taken[21];
map<int, int> m;
int tot=0;
int main(){
    cin >> k;
    memset(taken, 0, sizeof(taken));
    for(int i=1;i<=k;i++){
        cin >> pr[i];
    }
    cin >> x;
    for(int i=0;i<4;i++){
        cin >> combo[i];
    }
    cin >> t;
    for(int i=0;i<t;i++){
        int t;
        cin >> t;
        taken[t]++;
    }
    while(taken[combo[0]]+taken[combo[1]]+taken[combo[2]]+taken[combo[3]]){
        int temp = 0;
        for(int i=0;i<4;i++){
            if(taken[combo[i]]){
                temp += pr[combo[i]];
            }
        }
        x < temp ? tot += x : tot += temp;
        for(int i=0;i<4;i++){
            if(taken[combo[i]]){
                taken[combo[i]]--;
            }
        }
    }
    for(int i=0;i<21;i++){
        tot += pr[i]*taken[i];
    }
    cout << tot << "\n";
    return 0;
    

}