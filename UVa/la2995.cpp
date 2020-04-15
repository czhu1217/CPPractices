//image is everything
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define REP(i, n) for(int i=0;i<(n);i++)
const int MM = 10;
char pos[MM][MM][MM];
char view[6][MM][MM];
int n;
char read_char(){
    char c = getchar();
    while(true){
        if(c<='Z'&&c>='A')return c;
        c = getchar();
    }
}
void get(int k, int i, int j, int p, int &x, int &y, int &z){
    if(k==0){ x=p; y=j; z=i;}
    if(k==1){ x=n-1-j; y=p; z=i;}
    if(k==2){ x=n-1-p; y=n-1-j; z=i;}
    if(k==3){ x=j; y=n-1-p; z=i;}
    if(k==4){x=n-1-i;y=j;z=p;}
    if(k==5){x=i;y=j;z=n-1-p;}

}
int main(){
    while(scanf("%d", &n)&&n){
        REP(i, n) REP(k, 6) REP(j, n) view[k][i][j] = read_char();
        REP(i, n) REP(j, n) REP(k, n) pos[i][j][k] = '#';
        while(true){
            bool done = 1;
            REP(k, 6) REP(i, n) REP(j, n) if(view[k][i][j]!='.'){
                REP(p, n){
                    int x, y, z; 
                    get(k, i, j, p, x, y, z);
                    if(pos[x][y][z]=='.')continue;
                    if(pos[x][y][z]=='#'){
                        pos[x][y][z] = view[k][i][j];
                        break;
                    }
                    if(pos[x][y][z]==view[k][i][j]) break;
                    pos[x][y][z] = '.';
                    done = 0;
                }
            }
            if(done) break;
        }
        int ans=0;
        REP(i, n) REP(j, n) REP(k, n) if(pos[i][j][k]!='.')ans++;
        printf("%d\n", ans);
    }
    return 0;
}
