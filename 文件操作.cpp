创建并打开一个文本文档  -> 左上角文件 另存为 -> 下面选择所有文件 -> 输入文件名

data.in 里要提前保存样例  输出结果在data.out中

#include<cstdio> 
#define begin
int main() {
	#ifdef begin
	freopen("data.in", "r", stdin);    //重定向版本 
	freopen("data.out", "w", stdout);  // 只有定义了begin才执行这两条语句 
	#endif
	int x;
	int s = 0;
	while(scanf("%d", &x) == 1) {
		s += x;
	}
	printf("%d",s);
	return 0;
}

比赛中要求用文件输入输出 但禁止用重定向版本

#include<stdio.h>
int main() {
	FILE *fin, *fout;
	fin = fopen("data.in", "rb"); //fopen版本 
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
