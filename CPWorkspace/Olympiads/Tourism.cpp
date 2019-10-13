#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, k, k1, lookup[1000000][20], sum=0;
int at[1000005];


void buildSparseTable(int arr[], int n) 
{ 
    // Initialize M for the intervals with length 1 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = arr[i]; 
  
    // Compute values from smaller to bigger intervals 
    for (int j = 1; (1 << j) <= n; j++) { 
  
        // Compute minimum value for all intervals with 
        // size 2^j 
        for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
  
            // For arr[2][10], we compare arr[lookup[0][7]]  
            // and arr[lookup[3][10]] 
            if (lookup[i][j - 1] >  
                        lookup[i + (1 << (j - 1))][j - 1]) 
                lookup[i][j] = lookup[i][j - 1]; 
            else
                lookup[i][j] =  
                         lookup[i + (1 << (j - 1))][j - 1]; 
        } 
    } 
} 
int query(int L, int R) 
{ 
    // Find highest power of 2 that is smaller 
    // than or equal to count of elements in given 
    // range. For [2, 10], j = 3 
    int j = (int)log2(R - L + 1); 
  
    // Compute minimum of last 2^j elements with first 
    // 2^j elements in range. 
    // For [2, 10], we compare arr[lookup[0][3]] and 
    // arr[lookup[3][3]], 
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j]) 
        return lookup[L][j]; 
  
    else
        return lookup[R - (1 << j) + 1][j]; 
} 

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n;i++){
        scanf("%d", &at[i]);
        
    }
    k1 = n-k;
    int max1=0, max2=0;
    buildSparseTable(at, n);
    for(int i=k1-1;i<k;i++){
        if(query(0, i)+query(i+1,n-1)>sum) sum = query(0, i) + query(i+1,n-1);
    }
    printf("%d", sum);
}
    

    

