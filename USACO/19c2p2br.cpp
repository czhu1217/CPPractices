#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
pair<int, int> pi[1003];
int N, a[1003]; int mx = 2000, mi = 1, sum, ans;
bool vis[1003];
int main()
{
    ifstream fin("photo.in");
    ofstream cout("photo.out");
    memset(pi, 0, sizeof(pi));
    fin >> N;
    int hi = N, lo = 1;
    for(int i=2;i<=N;i++){
        fin >> a[i];
        ans += a[i];
        if(i%2==0){
            pi[i] = {-1, a[i]-pi[i-1].second};
            int l = pi[i].second - hi;
            if(l>mi) mi = l;
            int r = pi[i].second - lo;
            if(r<mx) mx = r;
        }
        else{
            pi[i] = {1, a[i]-pi[i-1].second};
            int r = hi - pi[i].second;
            if(r<mx) mx = r;
            int l = lo - pi[i].second;
            if(l>mi) mi = l;
        }
    }
    for(int i=1;i<=N;i++){
        int t = pi[i].first*mi + pi[i].second;
        if(!vis[t]) vis[t] = true;
        else{
            mi++; i=1;
            memset(vis, false, sizeof(vis));
        }
    }



    cout << mi << " ";
    for(int i=2;i<N;i++){
        int t = pi[i].first*mi + pi[i].second;
        cout << t << " ";
    }
    cout << pi[N].first*mi + pi[N].second;

    return 0;
}