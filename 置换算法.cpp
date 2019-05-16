#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int array[1000];

int numbers(int *a, int m) {
	int num = 0;
	for(int i = 0;i < m;++i) {
		if(a[i] != -1) {
			num++;
		}
	}
	return num;
}
void print(int *a, int m) {
	for(int i = 0;i < m;++i) {
		if(a[i] != -1) {
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
}
bool find(int *a, int m, int num) {
	for(int i = 0;i < m;++i) {
		if(a[i] == num) {
			return 1;
		}
	}
	return 0;
}
int fifo(int n, int m, int *array) {
	int sum = 0;
	int k = 0;
	int now = 0;
	int sign = 0;
	int ans[m];
	memset(ans,-1,sizeof(ans));
	while(n--) {
		if(numbers(ans, m) == m) {
			if(!find(ans, m, array[sign])) {
				ans[now++] = array[sign++];
				now %= m;
				print(ans, m);
				sum++;
			} else {
				sign++;
			}
		} else {
			ans[k++] = array[sign++];
			sum++;
			k %= m;
			print(ans, m);
		}
	}
	return sum;
}
int search_later(int *a, int n, int sign, int *b, int m) {
	int vis[m];
	int k = 0;
	memset(vis, -1, sizeof(vis));
	for(int i = sign + 1; i < n;++i) {
		for(int j = 0;j < m;++j) {
			if(a[i] == b[j]) {
				vis[j] = b[j];
				if(numbers(vis,m) == (m - 1)) {
					break;
				}
			}
		}
		if(numbers(vis,m) == (m - 1)) {
			break;
		}
	}
	for(int i = 0;i < m;++i) {
		if(vis[i] == -1) {
			return i;
		}
	}
}
int opt(int n, int m, int *array) {
	int sum = 0;
	int k = 0;
	int sign = 0;
	int ans[m];
	int x = n;
	memset(ans, -1, sizeof(ans));
	while(x--) {
		if(numbers(ans, m) == m) {
			if(!find(ans, m, array[sign])) {
				int q = search_later(array, n, sign, ans, m);
				ans[q] = array[sign++];
				print(ans,m);
				sum ++;
			} else {
				sign++;
			}
		} else {
			ans[k++] = array[sign++];
			k %= m;
			sum++;
			print(ans,m);
		}
	}
	return sum;
}
int search_early(int *a, int n, int sign, int *b, int m) {
	int vis[m];
	int k = 0;
	memset(vis, -1, sizeof(vis));
	for(int i = sign - 1; i >= 0;i--) {
		for(int j = 0;j < m;++j) {
			if(a[i] == b[j]) {
				vis[j] = b[j];
				if(numbers(vis,m) == (m - 1)) {
					break;
				}
			}
		}
		if(numbers(vis,m) == (m - 1)) {
			break;
		}
	}
	for(int i = 0;i < m;++i) {
		if(vis[i] == -1) {
			return i;
		}
	}
}
int lru(int n, int m, int *array) {
	int sum = 0;
	int k = 0;
	int sign = 0;
	int ans[m];
	int x = n;
	memset(ans, -1, sizeof(ans));
	while(x--) {
		if(numbers(ans, m) == m) {
			if(!find(ans, m, array[sign])) {
				int q = search_early(array, n, sign, ans, m);
				ans[q] = array[sign++];
				print(ans,m);
				sum ++;
			} else {
				sign++;
			}
		} else {
			ans[k++] = array[sign++];
			k %= m;
			sum++;
			print(ans,m);
		}
	}
	return sum;
	
}
int main() {
	int n, m;//进程号    内存块数
	cin>>n>>m;
	cout<<"输入页面走向:";
	for(int i = 0;i < n;++i) {
		cin>>array[i];
	}
	
	//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
	
	cout<<"先进先出置换算法"<<endl;
	int a = fifo(n, m, array);
	cout<<"缺页数为: "<<a<<endl;
	cout<<"缺页率为:"<<((double)a / n)<<endl;
	
	cout<<"最佳置换算法"<<endl;
	a = opt(n, m, array);	 
	cout<<"缺页数为: "<<a<<endl;
	cout<<"缺页率为:"<<((double)a / n)<<endl;
	
	cout<<"最近最久未使用置换算法"<<endl;
	a = lru(n, m, array);
	cout<<"缺页数为: "<<a<<endl;
	cout<<"缺页率为:"<<((double)a / n)<<endl;		
	return 0;
}
