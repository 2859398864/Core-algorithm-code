��������һ���ı��ĵ�  -> ���Ͻ��ļ� ���Ϊ -> ����ѡ�������ļ� -> �����ļ���

data.in ��Ҫ��ǰ��������  ��������data.out��

#include<cstdio> 
#define begin
int main() {
	#ifdef begin
	freopen("data.in", "r", stdin);    //�ض���汾 
	freopen("data.out", "w", stdout);  // ֻ�ж�����begin��ִ����������� 
	#endif
	int x;
	int s = 0;
	while(scanf("%d", &x) == 1) {
		s += x;
	}
	printf("%d",s);
	return 0;
}

������Ҫ�����ļ�������� ����ֹ���ض���汾

#include<stdio.h>
int main() {
	FILE *fin, *fout;
	fin = fopen("data.in", "rb"); //fopen�汾 
	fout = fopen("data.out", "wb");
	int x;
	int s = 0;
	while(fscanf(fin, "%d", &x) == 1) {
		s += x;
	}
	fprintf(fout, "%d", s);
	fclose(fin);
	fclose(fout);
	return 0;
}
