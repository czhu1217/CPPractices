//dfs to get size of each subtree
void dfs(int u, int p){
    sz[u] = 1;
    for(int v:adj[u]){
        if(v!=p&&!done[v]){
            dfs(v, u); sz[u] += sz[v];
        }
    }
}

//get Centroid of tree
int getCentre(int u, int p, int tot){
    for(int v:adj[u]){
        if(v!=p&&sz[v]*2>tot) return getCentre(v, u, tot);

    }
    return u;
}