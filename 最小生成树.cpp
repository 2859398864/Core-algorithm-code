kruskal

int kruskal(int m, int n) { //m： 边的个数  n： 顶点数
	int num = 0, ans = 0;
    sort(p,p+m,cmp);
    for(int i = 0;i < m;i++) {
        int fu = find(p[i].u);
		int fv = find(p[i].v);
        if(fu == fv) {
            continue;
        }
        ans += p[i].w;
        f[fu] = fv;
        if(++num == n - 1) { //已连边个数是点个数-1时，停止循环，最小生成树完成
            break;
        }
    }
    return ans;
}
