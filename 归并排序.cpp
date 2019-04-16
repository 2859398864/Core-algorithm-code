int temp[100000];
void mergesort(int *a, int left, int right){
    if(left == right) {
    	return;
	}
    int mid = (left + right) / 2;
    mergesort(a,left,mid);
	mergesort(a,mid+1,right);
    int i = left, j = mid + 1,k = left;
    while(i <= mid && j <= right) {
    	if(a[i] <= a[j]) {
        	temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}  
    while(i <= mid) {
    	temp[k++] = a[i++];
	}
    while(j <= right) {
    	temp[k++] = a[j++];
	}
    for(int i = left;i <= right; i++) {
    	a[i] = temp[i];
	}
}
//mergesort(a,0,n-1)
