//blindfold
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int r, c, m, cnt, dir, posx=0, posy=0;
char  op[30002];
bool map[377][82], b[377][82];
bool foward(int dir){
    switch(dir){
        case 0: posy--;
        break;
        case 1: posx++;
        break;
        case 2: posy++;
        break;
        case 3: posx--;
        break;
    }
    if(posy<0||posx<0||posy>r-1||posx>c-1||!map[posy][posx]) return false;
    return true;
}
bool trav(int r, int c,int dir){
    posy = r; posx = c;
    for(int i=0; i<m;i++){
       
        if(op[i]=='F'){
            if(!foward(dir)){

                return false;
            }
        }
        else if(op[i]=='L'){
            dir = (dir-1)%4;
        }
        else{
            dir = (dir+1)%4;
        } 
    }
    b[posy][posx] = true;
    return true;
}
int main(){
    memset(b, false, sizeof(b));
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char ch;
            cin >> ch;
            if(ch=='.') map[i][j] = true;
            else map[i][j] = false;
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> op[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<=3;k++)
                if(map[i][j]){
                    if(trav(i,j,k)){
                        break;
                    }
                }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(b[i][j]){
                cout << "*";
            }
            else if(map[i][j]) cout << ".";
            else cout << "X";
        }
        cout << "\n";
    }
    return 0;
}