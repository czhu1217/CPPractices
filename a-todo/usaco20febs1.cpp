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
int cow[100005], pos[100005], cycle[100005];
vector<int> v[100005];
int main(){
    //  ifstream cin("swap.in");
    //  ofstream cout("swap.out");
    
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++){
        cow[i] = i;
    }
    for(int i=0;i<M;i++){
        cin >> l[i] >> r[i];
    }

    for(int i=1;i<=M;i++){
        int le = l[i], ri = r[i];
        for(int k=0;k<=(int)(ri-le)/2;k++){
            int t = cow[le+k];
            cow[le+k] = cow[ri-k];
            cow[ri-k] = t;
        }
    }
    for(int i=1;i<=N;i++){
        pos[cow[i]] = i;
    }
    for(int i=1; i<=N;i++){
        int temp = pos[i];
            v[i].push_back(temp);
        while(temp!=i){
            temp = pos[temp];
            v[i].push_back(temp);

        }
    }
    for(int i=1;i<=N;i++){
        cout << v[i][(K-1)%v[i].size()] << "\n";
    }


    



    return 0;
}