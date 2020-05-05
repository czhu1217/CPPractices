#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long ll;
int ans[12];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int k = 1; k <= N; k++)
        {
            ans[k]=11;
            char a[505][505];
            int H, W;
            cin >> H >> W;
            for(int i=1;i<=H;i++)
                for(int j=1;j<=W;j++)
                    cin >> a[i][j];
            int l=W, r=0, hi=H, lo=0;
            for(int i=1;i<=H;i++){
                for(int j=1;j<=W;j++){
                    if(a[i][j]=='*'){
                        hi = min(hi, i);
                        lo = max(lo, i);
                        l = min(l, j);
                        r = max(r, j);
                    }
                }
            }
            if(r-l==0){
                ans[k]= 1; continue;
            }
            if(a[(int)ceil((lo+hi)/2.0)][l+1]!='*'&&a[(int)ceil((lo+hi)/2.0)][l]!='*'){
                if(a[lo][r]=='*'){ans[k]= 7;continue;}
                 ans[k]= 0; continue;
            }
            if(a[hi][l]=='*'){
                if(a[hi][r]=='*'){ans[k]= 4;continue;}
                ans[k]=3; continue;
                }
            if(a[hi+1][l]!='*'){
                if(a[lo-1][l]=='*'){ ans[k]= 2 ; continue;}
            }
            if(a[hi+1][r]!='*'){
                if(a[lo-1][l]=='*'){ ans[k]= 6 ; continue;}
                ans[k]= 5; continue;
            }
                if(a[lo-1][l]=='*'){ ans[k]= 8 ; continue;}
                ans[k]= 9; continue;

        

        }
        for(int i=1;i<=N;i++){
            cout << ans[i];
        }
        cout << "\n";


    }
    return 0;
}
