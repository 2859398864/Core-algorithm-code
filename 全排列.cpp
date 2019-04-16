#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int ans[4]={1,2,3,4};
	sort(ans,ans+4);    /* 这个sort可以不用，因为{1，2，3，4}已经排好序*/
	do                  /*注意这步，如果是while循环，则需要提前输出*/
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

