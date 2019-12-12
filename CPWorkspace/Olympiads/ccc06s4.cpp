#include <stdio.h>
using namespace std;
int N = 1, a[105][105], I;
bool shdBrk = false;
int main()
{
    while (N != 0)
    {
        shdBrk = false;
        scanf("%d", &N);
        if(N==0)
         return 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= N; k++)
                {
                    if (a[i][a[j][k]] != a[a[i][j]][k]){
                        shdBrk = true;
                        printf("no\n");
                        break;
                    }
                    
                }
                if (shdBrk)
                    break;
            }
            if (shdBrk)
                break;
        }
        if (shdBrk)
            continue;
        for(int i=1;i<=N;i++){
            int j, k;
            for(j=1;j<=N;j++){
                if(a[i][j]!=j) break;
            }
            if(j==N+1){
                for(k=1;k<=N;k++){
                    if(a[k][i]!=k) break;
                }
                if(k==N+1){
                    I = i;
                    // shdBrk = true;
                    break;
                }
            }
        }
        //   if (shdBrk)
        //     continue;
        for(int i=1;i<=N;i++){
            int j;
            for(j=1;j<=N;j++){
                if(a[i][j]==I&&a[j][i]==I) break;
            }
            if(j==N+1){
                shdBrk = true;
                break;
            }
        }
        if(!shdBrk){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }


    }
    return 0;
}