#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;
int T;
struct pi{
    int first, second, ind;
    bool operator<(const pi &e){
        return first<e.first;

    }
};
int main(){
    cin >> T;
    for(int x=1;x<=T;x++){
vector<pi> v;


        bool flg = false;
        char ans[100002];
        int N;
        cin >> N;
        for(int i=1;i<=N;i++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b, i});
        }
        sort(v.begin(), v.end());
        int end1 = 0, end2 = 0; bool work1 = false, work2 = false;
        int cnt = 0;
        for(auto e:v){
            if(e.first>end1) work1 = false;
            if(e.first>end2) work2 = false;
            if(end1<=e.first){
                work1 = true;
                end1 = e.second;
                ans[e.ind] = 'C';
            }
            else if(end2<=e.first){
                work2 = true;
                end2 = e.second;
                ans[e.ind] = 'J';
            }
            else{
                printf("Case #%d: IMPOSSIBLE\n", x);
                flg = true;
                break;
            }
        }
        if(!flg){
            printf("Case #%d: ", x);
           for(int i=1;i<=N;i++){
               cout << ans[i];
           }
           printf("\n");
        }
    }
    return 0;

}