#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int n;
map<char, int> m;
string st[10005];

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", &st[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<st[i].length();j++){
            m[st[i].at(j)]++;  
        }
    }
}