void quicksort(int *a, int left, int right) {
	int i = left, j = right;
	int mid = a[(i + j) / 2];
	while(i <= j) {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if(i < right) quicksort(a,i,right);
	if(j > left) quicksort(a,left,j);
}
//quicksort(a,0,n-1)
