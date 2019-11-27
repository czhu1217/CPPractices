#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
typedef pair<int, int> pi;
vector<pi> v;
int ar[2][100005];
 
int main(){
    scanf("%d", &N);
    for(int i=0, x, y;i<N;i++){
        scanf("%d %d", &x, &y);
        v.push_back({x,y});
    }
    scanf("%d", &M);
    for(int i=0;i<=M;i++){
        if(i==v[0].first){
            ar[0][i] = 1;
        }
        ar[0][i] = 0;
    }
    for(int i=0;i<v.size();i++){
        for(int j=1;j<=v[i].second;j++){
            
        }
    }


}