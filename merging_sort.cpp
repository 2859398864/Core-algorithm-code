#include<iostream>
#include<time.h>
#include<stdlib.h>
#define max 100000
using namespace std;
int temp[max];
void merge(int *a, int left, int mid, int right) {
	int i = left, j = mid + 1, n = 0, length = right - left;
	while(i <= mid && j <= right) {
		if(a[i] < a[j]) {
			temp[n++] = a[i++];
		} else {
			temp[n++] = a[j++];
		}
	}
	if(i > mid) {
		while(j <= right) {
			temp[n++] = a[j++];
		}
	} else {
		while(i <= mid) {
			temp[n++] = a[i++];
		}
	}
	for(int k = 0;k <= length;++k) {
		a[left+k] = temp[k];
	}
}
void mergesort(int *a, int left, int right) {
	if(left < right) {
		int mid = (left + right) / 2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int main() {
	srand((unsigned long)time(0));
	int a[10];
	for(int i = 0; i < 10;++i) {
		a[i] = rand()%1231;
	}
	mergesort(a,0,9);
	for(int i = 0; i < 10;++i) {
		cout<<a[i]<<" ";
	}
	return 0;
}
