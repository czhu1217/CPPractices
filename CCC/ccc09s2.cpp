#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
int r, c, a[32];
vector<unordered_set<int>> v;
int main(){
    cin >> r >> c;
    v.resize(r+2);
    for(int i=1;i<=r;i++){
        for(int j=1, t;j<=c;j++){
            cin >> t;
            if(t) a[i] += pow(2, j-1);
        }
        v[i].insert(a[i]);
    }
    for(int i=2, pre;i<=r;i++){
        pre = i-1;
        for(auto e:v[pre]){
            v[i].insert(e^a[i]);
        }
    }
    cout << v[r].size() << endl;
    return 0;

}