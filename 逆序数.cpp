给定一个数组A[0…N-1]，若对于某两个元素a[i]、a[j]，
若i＜j且a[i]＞a[j]，则称(a[i],a[j])为逆序对。
一个数组中包含的逆序对的数目称为该数组的逆序数。 

while(i <= mid && j <= right) {
		if(a[i] < a[j]) {
			temp[n++] = a[i++];
		} else {
			count += (mid - i + 1);  //修改归并排序的merge函数
			temp[n++] = a[j++];
		}
	}
//特别注意当输入多组数的时候count要初始化为0
