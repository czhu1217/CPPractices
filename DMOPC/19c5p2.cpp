
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
typedef pair<char, int>pci;
vector<pci> c, e;
bool prevc = false, preve = false;
int n, h;
int cntc, cnte;
int main(){
    cin >> n >> h;
    cntc = cnte = h;
    for(int i=0;i<n;i++){
        char ch; int x;
        cin >> ch >> x;
        c.push_back({ch, x});
    }
    for(int i=0;i<n;i++){
        char ch; int x;
        cin >> ch >> x;
        e.push_back({ch, x});
    }
    for(int i=0;i<n;i++){
        if(c[i].first=='A'){
            prevc = false;
        }
        else{
            prevc = true;
        }
        if(c[i].first=='A'&&!preve){
            cnte -= c[i].second;
        }
        else if(c[i].first=='D'&&preve){
            cnte -= e[i-1].second;
        }
        if(cnte<=0){
            cout << "VICTORY" << endl;
            return 0;
        }
        if(e[i].first=='A'){
            preve = false;
        }
        else  preve = true;
        if(e[i].first=='A'&&!prevc){
            cntc -= e[i].second;
        }
        else if(e[i].first=='D'&&prevc){
            cntc -= c[i].second;
        }
        if(cntc<=0){
            cout << "DEFEAT" << endl;
            return 0;
        }  
    }
    if(preve) cnte -= e[n-1].second;
    if(cnte<=0){
        cout << "VICTORY" << endl;
        return 0;

    } 
    cout << "TIE" << endl;
    return 0;

}