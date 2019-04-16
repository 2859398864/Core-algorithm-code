#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void ans(int *a, int n) {
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
int main() {
	srand((unsigned long)time(0));
	int a[10];
	for(int i = 0; i < 10;++i) {
		a[i] = rand()%1231;
	}
	ans(a,10);
	for(int i = 0; i < 10;++i) {
		cout<<a[i]<<" ";
	}
	return 0;
}
