
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
int N;
ll ans=0;
const int MM = 100005;
vector<int> x[100005], y[100005], prex[MM], sufx[MM], prey[MM], sufy[MM], sumx[MM], sumy[MM];
int main(){
    // ifstream cin("triangles.in");
    // ofstream cout("triangles.out");
    cin >> N;
    for(int i=0;i<N;i++){
        int u, v;
        cin >> u >> v;
        u += 10000; v += 10000;
        x[u].push_back(v);
        y[v].push_back(u);
    }
    int psum = 0, ssum = 0;

    ll p=0;
    for(int i=0;i<2*10004; i++){
        for(int j=0;j<x[i].size(); j++){
            ssum += x[i][j]-x[i][0];
        }
        for(int j=1;j<x[i].size(); j++){
            
        }

    }
}