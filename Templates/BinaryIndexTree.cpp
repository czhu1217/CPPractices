int query(int pos){
    int sum=0;
    for(int i=pos;i>0;i-=i&-i){
        sum+=bit[i];
    }
    return sum;
}

void update(int pos, int v){
    for(int i=pos; i<bit.length();i+=i&-i){
        bit[i]+=v ;
    }
}

const int MM = 1e9;
int bit[MM];