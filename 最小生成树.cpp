kruskal

int kruskal(int m, int n) { //m�� �ߵĸ���  n�� ������
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
        if(++num == n - 1) { //�����߸����ǵ����-1ʱ��ֹͣѭ������С���������
            break;
        }
    }
    return ans;
}
