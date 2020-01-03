#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int N, mx=0;
vector<int> v;
map<int, int> m;
int main(){
    scanf("%d", &N);
    for(int i=0, x;i<N;i++){
        scanf("%d", &x);
        m[x]++;
        if(m[x]>mx){
            mx = m[x];
        }
    }
    for(auto e:m){
        if(e.second==mx){
            printf("%d ", e.first);
        }
    }
    return 0;
 


}

