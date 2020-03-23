#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MM = 1e5+5, LOG =17;
int N, M, st[LOG][MM];
int rmq(int x, int y){
    int lvl = log2(y-x+1);
    return max(st[lvl][x], st[lvl][y-(1<<lvl)+1]);
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++) scanf("%d", &st[0][i]);
    for(int i=1;i<LOG;i++){
        for(int j=1;j+(1<<i)-1<=N;j++){
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i=1, x, y;i<=M;i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", rmq(x, y));
    }

}