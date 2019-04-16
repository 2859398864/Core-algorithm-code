#include<iostream>
#include<cstdio>
using namespace std;

int num[1000000], len;

void init() {
	len = 1;
	num[0] = 1;
}
int mult(int num[], int len, int n) {
	long long tmp = 0;
	for(long long i = 0;i < len;++i) {
		tmp = tmp + num[i] * n;
		num[i] = tmp % 10;
		tmp /= 10;
	}
	while(tmp) {
		num[len++] = tmp % 10;
		tmp /= 10;
	}
	return len;
}

int main() {
	int n;
	cin>>n;
	init();
	for(int i = 2;i <= n;++i) {
		len = mult(num,len,i);
	}
	for(int i = len - 1;i >= 0;i--) {
		printf("%d",num[i]);
	}
	return 0;
}
