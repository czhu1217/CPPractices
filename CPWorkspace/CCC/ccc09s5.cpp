//wireless
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int N, M, K, dif[1003][30003], mx, cnt=0;
int main(){
    cin >> N >> M >> K;
    for(int i=0, x, y, r, b;i<K;i++){
        cin >> x >> y >> r >> b;
        for(int j=max(1, x-r);j<=min(N, x+r);j++){
            int d = sqrt(r*r-(x-j)*(x-j));
            dif[j][(max(1, y-d))] +=b;
            dif[j][min(M+1, y+d+1)] -=b;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dif[i][j] += dif[i][j-1];
            if(dif[i][j]>=mx){
            if(dif[i][j]>mx){
                cnt = 1;
                mx = dif[i][j];
            }
            else{
                cnt++;
            }
        }
        }
    }
    cout << mx << "\n" << cnt << "\n";
}
