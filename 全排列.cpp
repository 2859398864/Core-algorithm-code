#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int ans[4]={1,2,3,4};
	sort(ans,ans+4);    /* ���sort���Բ��ã���Ϊ{1��2��3��4}�Ѿ��ź���*/
	do                  /*ע���ⲽ�������whileѭ��������Ҫ��ǰ���*/
	{
		for(int i=0;i<4;++i)
			cout<<ans[i]<<" ";
		cout<<endl;
	}while(next_permutation(ans,ans+4));
	return 0;
}


void perm(int *a, int low, int high) {
	if(low == high) {
		for(int i = 0;i <= low;++i) {
			printf("%d ",a[i]);
		}
		printf("\n");
	} else {
		for(int i = low;i <= high;++i) {
			swap(a[i],a[low]);
			perm(a,low+1,high);
			swap(a[i],a[low]);
		}
	}
}
//perm(a,0,n-1)

