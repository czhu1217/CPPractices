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
int main(){
    int p, n, r;
    cin >> p >> n >> r;
    cout << log(ceil(p/n))/log(r);
    return 0;



}