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
typedef long long ll;
#define f first
#define s second
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    if(a+b<=c) {
        cout << "no" << endl;
        return 0;
    }
    if(a+c<=b){
        cout << "no" << endl;
        return 0;
    }
    if(b+c<=a){
        cout << "no" << endl; 
        return 0;
    }
    cout << "yes" << endl;
    return 0;


}