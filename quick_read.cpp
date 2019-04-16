#include<iostream>

using namespace std;

//cin << scanf < cin(关闭流同步) < read << fread
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int main(){
	int a;
	a = read();
	cout<<a;
	return 0;
}

