#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//replace the real score with a virtual ranking then do binary search
int bit[100001], rk[100001], num;
vector<int> a;
void upd(int x){
    for(int i=x;i<=num;i+=i&(-i)){
        bit[i]+=2;
    }
}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=i&-i){
        sum += bit[i];
    }
    return sum;
}

int main(){
    int score;
    double total=0;
    scanf("%d", &num);
    vector< pair<int,int> > pi;
    for(int i=0;i<num;i++){
        scanf("%d", &score);
        pi.push_back(make_pair(score, i));
    }
    sort(pi.begin(), pi.end());
    for(int i=0;i<num;i++){
        rk[pi[i].second] = num-i;
        
    }
    
    for(int i=0;i<num;i++){
        upd(rk[i]);
        total += query(rk[i]);
    }
    printf("%.2f", total/num);
    return 0;




}
