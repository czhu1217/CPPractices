#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
int N, Q, B, cnt, a[102];
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a, a+N);
    for(int i=0;i<N;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}