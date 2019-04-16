int f[10010];
int find(int k){
    if(f[k] == k) {
    	return k;
	}
    return f[k] = find(f[k]);
}
void join(int x,int y) {
    int fx = find(x); 
	int fy = find(y);                                        
	f[fx] = fy;                      
}
for(int i = 1;i <= 100;++i) {
    f[i] = i;
}
//切记  f数组一定要初始化
