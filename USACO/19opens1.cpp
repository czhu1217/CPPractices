//AC
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
typedef  long long ll;
int N, cnt=0; 
bool cow[1002][1002];    bool r[1002], c[1002];
queue<int> vr, vc;
int ans1, ans2;
bool solve(int a, int b){
    // fout << a << " " << b << "\n";
    int cnt = 0;

    for(int i=1;i<=N;i++) c[i] = cow[a][i];
    for(int i=1;i<=N;i++){
        if(i==a){
            r[i] = cow[i][b]^c[i];
        }
        else r[i] = cow[i][b];
    }
    // for(int i=1;i<=N;i++) fout << r[i] << " ";
    // fout << "\n";
    // for(int i=1;i<=N;i++){
    //     fout << c[i] << " ";

    // }
    // fout << "\n";
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cow[i][j]^r[i]^c[j]){
                cnt++;
                ans1 = i; ans2 = j;
            } 
        }
    }
    if(cnt==1){
  
        return true;
    }
    return false;
}
int main(){
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");
    fin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char c;
            fin >> c;
            if(c=='L'){
                cow[i][j] = 1;
            }
            else cow[i][j] = 0;
        }
    }
    if(solve(1, 1)){
              fout << ans1 << " " << ans2 << "\n";
              return 0;}
              if(solve(2, 2)){
              fout << ans1 << " " << ans2 << "\n";
              return 0;}
              if(solve(N, N)){
              fout << ans1 << " " << ans2 << "\n";
              return 0;}

    fout << -1 << "\n";
    return 0;

    

}