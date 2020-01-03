#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int n;
bool b=false;
string s[3];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin >> s[0] >> s[1]>> s[2];
        size_t found;
        b = false;
        for(int j=0;j<3;j++){
            b=false;
            string t = s[(j+1)%3];
            if(s[j].find(t) == string::npos && t.find(s[j])== string::npos) continue;
            if(s[j].find(t)==0){
                cout << "No" << endl;
                b=true;
                break;
            }
            if(s[j].find(t)+t.length()==s[j].length()){
                cout << "No" << endl;
                b=true;
                break;
            }

            if(t.find(s[j])==0){
                cout << "No" << endl;
                b = true;
                break;
            }
            if(t.find(s[j])+s[j].length()==t.length()){
                cout << "No" << endl;
                b=true;
                break;
            }
        }
        if(!b){
            cout << "Yes" << endl;
        }
    }
    return 0;
}