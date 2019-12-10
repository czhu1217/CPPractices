//Using difference array
#include <stdio.h>
#include <vector>
#include <map>
struct windo{  int x1, x2, y1, y2, t;} win[1001];
using namespace std;
map<int, int> rx, ry;
vector<int, int> vx, vy;
int dif[2002][2002], N, T;
int main(){
    scanf("%d %d", &N, &T);
    for(int i=1;i<=N;i++){
        scanf("%d %d %d %d %d", &win[i].x1, &win[i].y1, &win[i].x2, &win[i].y2, &win[i].t);
        rx[win[i].x1]  = rx[win[i].x2] = 0; ry[win[i].y1] = ry[win[i].y2] = 0;
    
    }
    int cntx, cnty = 0;
    for(auto &it:rx){
        it.second = ++cntx;
        vx.push_back(it.first);

    }
    for(auto &it:ry){
        it.second = ++cnty;
        vy.push_back(it.first);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
        }
    }



}

