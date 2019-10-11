#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int  r, co, sx, sy, xsize, ysize;
queue<pair<int, int>> op;
bool vis[200][200];
char c[2000][2000];
void readInput(){

    scanf("%d %d", &xsize, &ysize);
    for(int i=0;i<xsize;i++){
        for(int j=0;j<ysize;j++){
            printf("%d %d", i, j);
            scanf("%c", &c[i][j]);
            if(c[i][j]=='R'){
                printf("%d %d", i, j);
                sx = i;
                sy = j;
            }

        }
    }

}
int search(int x, int y){
    printf("%d %d", x, y);
    vis[x][y] = true;
    if(c[x][y]=='C'){
        printf("%s %d %d", "found", x, y);
        return 0;


    } 
    if(x<r&&y<co){
        if(!vis[x-1][y]&&c[x-1][y]=='.'){
            op.push(make_pair(x-1, y));

        }
        if(!vis[x+1][y]&&c[x+1][y]=='.'){
            op.push(make_pair(x+1, y));
        }
        if(!vis[x][y-1]&&c[x][y-1]=='.'){
            op.push(make_pair(x, y-1));

        }
        if(!vis[x][y+1]&&c[x][y+1]=='.'){
            op.push(make_pair(x, y+1));

        }
    }
    pair<int, int> t = op.front();
    op.pop();
    return 1+search(t.first, t.second);
}

int main(){
    readInput();

    int counter = search(sx, sy);
    printf("%d", counter);
}
    


