#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef  long long ll;
int N, cnt=0; bool r[1000002], c[1000002];
queue<int> vr, vc;
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1, x;j<=N;j++){
            scanf("%d", &x);
            if(i==1){
                if(x){
                    c[j] = true;
                    cnt++;

                } 
                else c[j] = false;
            }
            if(j==1){
                if(x) r[i] = !c[1];
                else r[i] = c[1];
                if(r[i]) cnt++;
            }
            if(r[i]^c[j]!=x){
                cout << -1 << endl;
                return 0;
            }
            
        }
    }
    cout << cnt << endl;
    for(int i=1;i<=N;i++){
        if(r[i]){
            cout << "R " << i << endl;
        }
    }
    for(int i=1;i<=N;i++){
        if(c[i]){
            cout << "C " << i << endl;
        }
    }

    return 0;
    

}