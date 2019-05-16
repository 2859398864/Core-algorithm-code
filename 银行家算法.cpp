#include<iostream>
using namespace std;
struct max{
	int a;
	int b;
	int c;
}m[100];
struct allocation{
	int a;
	int b;
	int c;
}action[100];
struct need{
	int a;
	int b;
	int c;
}nd[100];
struct available{
	int a;
	int b;
	int c;
}able;
int vis[100];
int ans[100], k =  0;
int main() {
	int p, s;
	cout<<"请输入进程个数  资源种类:"<<endl;
	cin>>p>>s;
	cout<<"请输入所需MAX资源数量:"<<endl;
	for(int i = 0;i < p;++i) {
		cin>>m[i].a >>m[i].b >>m[i].c ;	
	}
	cout<<"请输入已分配资源数量:"<<endl;
	for(int i = 0;i < p;++i) {
		cin>>action[i].a >>action[i].b >>action[i].c ;
	}
	for(int i = 0;i < p;++i) {
		nd[i].a  = m[i].a - action[i].a ;
		nd[i].b  = m[i].b - action[i].b ;
		nd[i].c  = m[i].c - action[i].c ;
	}
	cout<<"请输入available资源:"<<endl;
	cin>>able.a >>able.b >>able.c ;
	int flag = 0;
	int num = p;
	while(num) {
		flag = 0;
		for(int j = 0;j < p;++j) {
			if(able.a >= nd[j].a && able.b >= nd[j].b && able.c >= nd[j].c && !vis[j]) {
				able.a += nd[j].a;
				able.b += nd[j].b;
				able.c += nd[j].c;
				vis[j] = 1;
				flag = 1;
				ans[k++] = j;
				num--;
			}
		}
		if(!flag) {
			cout<<"没有安全性算法!"<<endl;
			return 0;
		}
	}
	if(flag) {
		cout<<"其中一个安全性算法为:"<<endl;
		for(int i = 0;i < k;++i) {
			if(i == 0) {
				cout<<"p"<<ans[i];
			} else {
				cout<<"->"<<"p"<<ans[i];
			}
		}
	}	
	return 0;
}

/*
5 3
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
3 3 2



*/
