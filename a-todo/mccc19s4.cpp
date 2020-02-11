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
int N, Q, B;
int a[100005];

int main(){
    cin >> N >> Q >> B;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    char op;
    for(int i=0;i<Q;i++){
        cin >> op;
        if(op=='U'){
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int cur = 0, b = 1;
            for(int k=l;k<=r;k++){
                if(cur+a[k]<=B){
                    cur += a[k];
                }
                else if(a[k]>B){
                    b = -1;
                    break;
                }
                else{
                    cur = a[k];
                    b++;
                }
            }
            cout << b << endl;
        
        }
    }
    return 0;

}