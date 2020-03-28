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
using namespace std;
int aa1, bb1, aa2, aa3, aa4, bb2, bb3, bb4; long double m1, m2, b1, b2;
bool und1=false, und2=false;
double mul = 1e5;
int main(){
    cin >> aa1 >> bb1 >> aa2 >> bb2 >> aa3 >> bb3 >> aa4 >> bb4;
    if(aa2!=aa1){
        m1 = (bb2-bb1)/((aa2-aa1)*1.0);
    }
    else und1 = true;
    if(aa3!=aa4)
    m2 = (bb4-bb3)/((aa4-aa3)*1.0);
    else und2 = true;
    if(!und1){
        b1 = bb1 - aa1*m1;
    }
    else b1 = aa1;
    if(!und2){
        b2 = bb3 - aa3*m2;
    }
    else b2 = aa3;
    if(und1&&und2){
        if(aa1==aa3){
            cout << "coincident" << "\n";
        }
        else{
            cout << "parallel" << "\n";
        }
    }
    else if(und1&&(!und2)){
        double a = aa1;
        double b = aa1*1.0*m2+b2;
        printf("%.7f %.7f", a, b);
    }
    else if((!und1)&&und2){
        double a = aa3;
        double b = aa3*1.0*m1 + b1;
        printf("%.7f %.7f", a, b);
    }
    else{
        if(m1==m2){
            if(b1==b2) cout << "coincident" << endl;
            else cout << "parallel" << endl;
        }
        else{
        double a, b;
        a = (b2-b1)/(m1-m2);
        b = a*m1+b1;
        printf("%.7f %.7f", a, b);
        }
    }
    return 0;


}