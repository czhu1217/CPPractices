#include <stdio.h>
int N;
long long seq[11];
bool a = true, g = true;
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        a=true; g=true;

        for(int j=0;j<10;j++){
            scanf("%lld", &seq[j]);
        
        }
  
        for(int j=2;j<10;j++){
            if(!(seq[j-2]*seq[j]==seq[j-1]*seq[j-1])) g = false;
            if(!(seq[j-2]+seq[j]==2*seq[j-1])) a = false;
        }
        if(a&&g) printf("both\n");
        else if(a) printf("arithmetic\n");
        else if(g) printf("geometric\n");
        else printf("neither\n");
        
    }
    return 0;
}