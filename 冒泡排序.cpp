void bubblesort(int *a, int n) {
	int i, j, flag;
	for(i = 0;i < n - 1;++i) {
		flag = 0;
		for(j = 0;j < n - i - 1;++j) {
			if(a[j] > a[j+1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 1;
			}
		}
		if(!flag) {
			break;
		}
	}
}
//bubblesort(a, n)
