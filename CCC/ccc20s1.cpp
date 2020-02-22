#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
int N;
vector< pair<int, int> > v;
double mx = 0.0;
int main(){
    cin >> N;
    for(int i=0, x, y;i<N;i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    double temp;
    sort(v.begin(), v.end());

    for(int i=1;i<v.size();i++){
        temp = (double)abs(v[i].second-v[i-1].second)/(double)(v[i].first-v[i-1].first);
        if(temp>mx) mx = temp;
    }
    cout << mx << endl;
    return 0;

}