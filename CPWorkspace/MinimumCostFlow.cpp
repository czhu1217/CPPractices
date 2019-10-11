#include <iostream>
#include <vector>
using namespace std;
int useless = 0;
int dfs(int v,int parent, int id, bool vis[], int num[], vector<int> list[], bool inprocess[]){
    vis[v] = true;
    inprocess[v] = true;
    num[v] = id;
    for(int i=0;i<list[v].size();i++){
        if(!vis[list[v][i]]){
            
            dfs(list[v][i],v, id, vis, num, list, inprocess);
        }
        else if(inprocess[list[v][i]]){
            useless++;
        }
    }
    inprocess[v] = false;
    return 0;


}
int main(){
    
    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    vector<int>* adj = new vector<int>[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);


    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<adj[i].size();j++){

        }

    }
    int num = 0;
    bool* vis = new bool[n+1];
    bool* inprocess = new bool[n+1];
    for(int i=0;i<n+1;i++){
        vis[i] = false;
        inprocess[i] = false;
    }
    vis[0] = true;
    int* id = new int[n+1];
    

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0,num,vis,id,adj,inprocess);
            num++;
        }
        
    }

    num -= 1;   

    int discount = k < useless ? k : useless;

    if(k>=num){

        cout << 0 << endl;

    }
    else{
        cout << num - discount << endl;

    }

     return 0;


    



}

