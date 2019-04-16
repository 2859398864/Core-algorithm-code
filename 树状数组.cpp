int tree[500100], n;
int lowbit(int x){
    return x & -x;
}
void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}


1 单点更新与区间求和


int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
            add(b,c);//将某一个数加上c
        if(a==2)
            cout<<sum(c)-sum(b-1)<<endl; //求出某区间每一个数的和
    }
    return 0;
}

2 区间更新与单点求值

int main(){
    cin>>n>>m;
    int now = 0;
    for(int i=1;i<=n;i++) {
    	int a;
    	cin>>a;
    	add(i,a-now);
    	now = a;
	}
	for(int i=1;i<=m;i++){
    	int a;
    	scanf("%d",&a);
    	if(a==1){
        	int x,y,z;
        	scanf("%d%d%d",&x,&y,&z);
       	 	add(x,z);     //将某区间
        	add(y+1,-z);  //每一个数数加上x
    	}
    	if(a==2){
        	int x;
        	scanf("%d",&x);
        	printf("%d\n",sum(x)); //求出某一个数的值
    	}
	}
	return 0;
}
