#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
int N, M, K;
int l[102], r[102];
int cow[2][100005], pos[100005];
int main(){
     ifstream cin("swap.in");
     ofstream cout("swap.out");
    
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        cow[0][i] = i;
    }
    for(int i=1;i<=M;i++){
        cin >> l[i] >> r[i];
    }
        for(int j=1;j<=M;j++){
            int le = l[j], ri = r[j];
            for(int k=0; k<=(int)(ri-le)/2;k++){
                int temp = cow[0][le+k];
                cow[0][le+k] = cow[0][ri-k];
                cow[0][ri-k] = temp;
            }
        }
    K--;
    for(int i=1;i<=N;i++){
        pos[cow[0][i]] = i;
    }
    int cur = 1, pre = 0;
    for(int i=0;i<K;i++){
        for(int i=1;i<=N;i++){
            cow[cur][pos[i]] = cow[pre][i];
        }
        swap(cur, pre);
    }
    for(int i=1;i<=N;i++){
        cout << cow[pre][i] << "\n";
    }



    return 0;
}