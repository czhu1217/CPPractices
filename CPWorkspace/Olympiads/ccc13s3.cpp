#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int fav, done, a, b, av, bv, cnt=0, counter=0, mx=0, win;
int ar[5];
bool played[5][5];
vector<pair<int, int>> v;
int main(){
    cin >> fav >> done;
    for(int i=0;i<done;i++){
        cin >> a >> b >> av >> bv;
        played[a][b] = true;
        played[b][a] = true;
        if(av>bv){
            ar[a]+=3;
        }
        else if(bv>av){
            ar[b]+=3;
        }
        else{
            ar[a]++;ar[b]++;
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            if(!played[i][j]){
                v.push_back({i, j});
            }
        }
    }
    recur();
    cout << cnt << "\n";
}

void recur(){
    if(v.empty()){
        for(int i=1;i<4;i++){
            if(ar[i]>mx){
                win = i;
            }
        }
        counter++;
        if(win==fav) cnt++;
        return;
    }
    int x, y;
    x = v.back.first;
    y = v.back.second;
    v.pop_back();
    ar[x]+=3;
    recur();
    ar[x]-=3;
    ar[y]+=3;
    recur();
    ar[y]-=3;
    ar[x]++;ar[y]++;
    recur();
    ar[x]--;ar[y]--;
    v.push_back({x, y});

}