#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 100501
struct NODE{
	int w;
	int to;
	int next; //next[i]表示与第i条边同起点的上一条边的储存位置
}edge[MAXN];
int cnt = 1;
int head[MAXN]; 
void add(int u,int v,int w){
	edge[cnt].w=w;
	edge[cnt].to=v;    //edge[i]表示第i条边的终点 
	edge[cnt].next=head[u]; //head[i]表示以i为起点的最后一条边的储存位置 
	head[u]=cnt++;
}
int main(){
	memset(head,0,sizeof(head));  //重点 
	cnt=1;
	int n, m;
	cin>>n>>m;
	int a,b,c;
	for(int i = 1;i <= m;++i) {
		cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int i = 1;i <= n;++i) {
		for(int j = head[i];j;j = edge[j].next ) {
			cout<<i<<"->"<<edge[j].to <<" "<<edge[j].w ;
			cout<<endl;
		}
	}
	return 0;
}

