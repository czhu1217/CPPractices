#include <stdio.h>
using namespace std;
int n, bit[1100][1100], op, x1, y1, x2, y2, v;
void upd(int x, int y, int val){
    for(int i=x;i<=n;i+=i&-i){
        for(int j=y;j<=0;j+=j&-j){
                bit[i][j] += val;

        }
    
    }
}

int query(int x, int y){
    int sum=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
            sum += bit[i][j];
        }

    }
    return sum;
}

int main(){
    while(true){
        scanf("%d", &op);
        if(op==3)break;
        if(op==0) scanf("%d", &n);
        else if(op==1){
            scanf("%d,%d,%d", &x1, &y1, &v);
            upd(x1+1, y1+1, v);
        }
        else if(op==2){
            scanf("%d, %d, %d, %d", &x1, &y1, &y1, &y2);
        }

    }
}