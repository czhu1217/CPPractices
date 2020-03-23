#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
typedef  long long ll;
int N, cnt=0; bool r[1002], c[1002];
bool cow[1002][1002];
queue<int> vr, vc;
int ans1, ans2;
int main(){
    // ifstream cin("leftout.in");
    // ofstream cout("leftout.out");
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char c;
            cin >> c;
            if(c=='L'){
                cow[i][j] = 1;
            }
            else cow[i][j] = 0;
        }
    }
    for(int i=N;i>0;i--){
        bool flg = false;
        bool tog = false;
        for(int j=N, x;j>0;j--){
            x = cow[i][j];
            if(tog) x = !x;
            if(i==N){
                if(x){
                    c[j] = true;
                } 
                else c[j] = false;
            }
            if(j==N){
                if(x) r[i] = !c[N];
                else r[i] = c[N];
            }
            if(r[i]^c[j]!=x){
                if(j==N-1&&(r[i]^c[j-1]!=cow[i][j-1])){
                    tog = true;
                    ans1 = i;
                    ans2 = j+1;
                    cnt++;
                    continue;
                }
                ans1 = i;
                ans2 = j;
                cnt++;
            }
            
        }
    }

    if(cnt==1)
    cout << ans1 << " " << ans2 << "\n";
    else cout << -1 << "\n";
    
    return 0;
    

}