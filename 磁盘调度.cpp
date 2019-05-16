#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio> 
#include<algorithm>

using namespace std;

void fcfs(int *a, int start, int len) {
	int sum = 0;
	for(int i = 0;i < len - 1;++i) {
		sum += (abs(start - a[i]));
		cout<<"�����ʴŵ��ţ�"<<a[i]<<"  "<<"�ƶ����룺"<<abs(start-a[i])<<endl;
		start = a[i];
	}
	cout<<"ƽ��Ѱ�����ȣ�"<<(double)sum / (len - 1)<<endl;
	
} 
int k(int *b, int now, int len) {
	int i, minn, cmp;
	for(i = 0;i < len - 1;++i) {
		if(b[i] != -1) {
			minn = i;
			cmp = abs(now - b[i]);
			break;
		}
	}
	for(int j = 0;j < len - 1;++j) {
		if(b[j] != -1 && j != i) {
			int t = abs(now - b[j]);
			if(t < cmp) {
				minn = j;
				cmp = t;
			}
		}
	}
	b[minn] = -1;
	return minn;
}
void sstf(int *a, int start, int len) {
	int sum = 0;
	int b[1000];
	for(int i = 0;i < len - 1;++i) {
		b[i] = a[i];
	}
	for(int i = 0;i < len - 1;++i) {
		int t = k(b,start,len);
		sum += (abs(a[t] - start));
		cout<<"�����ʴŵ��ţ�"<<a[t]<<"  "<<"�ƶ����룺"<<abs(start-a[t])<<endl;
		start = a[t];
		
	}
	cout<<"ƽ��Ѱ�����ȣ�"<<(double)sum / (len - 1)<<endl;
}



int cmp(int a, int b) {
	return a > b;
	 
}
void scan(int *a, int start, int len) {
	int sum = 0;
	int b[1000];
	for(int i = 0;i < len - 1;++i) {
		b[i] = a[i];
	}
	sort(b,b+len - 1);
	for(int i = 0;i < len - 1;++i) {
		if(b[i] >= start) {
			sum += abs(start - b[i]);
			cout<<"�����ʴŵ��ţ�"<<b[i]<<"  "<<"�ƶ����룺"<<abs(start-b[i])<<endl;
			start = b[i];
			b[i] = -1;
		}
	}
	sort(b,b+len - 1,cmp);
	for(int i = 0;i < len - 1;++i) {
		if(b[i] != -1) {
			sum += abs(start-b[i]);
			cout<<"�����ʴŵ��ţ�"<<b[i]<<"  "<<"�ƶ����룺"<<abs(start-b[i])<<endl;
			start = b[i];
			b[i] = -1;
		}
	}
	cout<<"ƽ��Ѱ�����ȣ�"<<(double)sum / (len - 1)<<endl;
}


void cscan(int *a, int start, int len) {
	int sum = 0;
	int b[1000];
	for(int i = 0;i < len - 1;++i) {
		b[i] = a[i];
	}
	sort(b,b+len - 1);
	for(int i = 0;i < len - 1;++i) {
		if(b[i] >= start) {
			sum += abs(start - b[i]);
			cout<<"�����ʴŵ��ţ�"<<b[i]<<"  "<<"�ƶ����룺"<<abs(start-b[i])<<endl;
			start = b[i];
			b[i] = -1;
		}
	}
	sort(b,b+len - 1);
	for(int i = 0;i < len - 1;++i) {
		if(b[i] != -1) {
			sum += abs(start-b[i]);
			cout<<"�����ʴŵ��ţ�"<<b[i]<<"  "<<"�ƶ����룺"<<abs(start-b[i])<<endl;
			start = b[i];
			b[i] = -1;
		}
	}
	cout<<"ƽ��Ѱ�����ȣ�"<<(double)sum / (len - 1)<<endl;
}
int main() {
	int arr[1000];
	int start;
	cout<<"���뿪ʼ�ŵ���:";
	cin>>start;
	cout<<endl<<"���뱻���ʴŵ��ţ���EOF��β"<<endl;
	int len = 0;
	while(cin>>arr[len++]);
	//fcfs(arr,start,len);  //�����ȷ��� 
	//sstf(arr,start,len);  //���Ѱ��ʱ������ 
	//scan(arr,start,len);  //ɨ���㷨 
	cscan(arr,start,len);   //ѭ��ɨ���㷨 
	return 0;
}
/*
100
55
58
39
18
90
160
150
38
184
eof
*/
