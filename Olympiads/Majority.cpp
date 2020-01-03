#include <vector>
#include <stdio.h>
int N, gud, bad, t, pre; long long  ans=0;
using namespace std;
vector<int> bit(150005*2);

int query(int pos){
    pos += 150005;
    int sum=0;
    for(int i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}
void update(int pos){
    pos += 150005;
    for(int i=pos; i<bit.size();i+=i&-i){
        bit[i]++ ;
    }
}
int main(){
    scanf("%d", &N);
    update(0);
    for(int i=1;i<=N;i++){
        scanf("%d", &t);
        if(t==1){
            pre+=1;
        }
        else{
            pre-=1;
        }
        ans += query(pre-1);
        update(pre);
    }
    printf("%lld\n", ans);
    return 0;
}

