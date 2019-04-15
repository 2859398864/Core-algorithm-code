### **阶乘**

```c++
#include<iostream>
#include<cstdio>
using namespace std;

int num[1000000], len;

void init() {
	len = 1;
	num[0] = 1;
}
int mult(int num[], int len, int n) {
	long long tmp = 0;
	for(long long i = 0;i < len;++i) {
		tmp = tmp + num[i] * n;
		num[i] = tmp % 10;
		tmp /= 10;
	}
	while(tmp) {
		num[len++] = tmp % 10;
		tmp /= 10;
	}
	return len;
}

int main() {
	int n;
	cin>>n;
	init();
	for(int i = 2;i <= n;++i) {
		len = mult(num,len,i);
	}
	for(int i = len - 1;i >= 0;i--) {
		printf("%d",num[i]);
	}
	return 0;
}
```

### 大数相加

```c++
string add(string s1, string s2) {
	if(s1 == "" && s2 == "") return "0";
	if(s1 == "") return s2;
	if(s2 == "") return s1;
	string maxx = s1, minn = s2;
	if(s1.length() < s2.length() ) {
		maxx = s2;
		minn = s1;
	}
	int a = maxx.length() - 1, b = minn.length() - 1;
	for(int i = b;i >= 0;i--) {
		maxx[a--] += minn[i] - '0';
	}
	for(int i = maxx.length() - 1;i > 0;i--) {
		if(maxx[i] > '9') {
			maxx[i] -= 10;
			maxx[i-1] ++;
		}
	}
	if(maxx[0] > '9') {
		maxx[0] -= 10;
		maxx = '1' + maxx;
	}
	return maxx;
} 
```

### 快速幂

> sum = 2 ^ n   sum的位数   n * log10(2) + 1

```c++
int qpow(long long  a, long long  b) {        //qpowmod(ll a, ll b, ll m)
    long long ans = 1, base = a;              //base = a % m
    while(b > 0) {
        if(b & 1) {
            ans *= base;                      //ans = ans * base % m 
        }
        base *= base;                         //base = base * base % m
        b >>= 1;
    }
    return ans;                               //ans % m       
}
```

### 快排

```c++
void quicksort(int *a, int left, int right) {
	int i = left, j = right;
	int mid = a[(i + j) / 2];
	while(i <= j) {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if(i < right) quicksort(a,i,right);
	if(j > left) quicksort(a,left,j);
}
//quicksort(a,0,n-1)
```

### 归并排序

```c++
int temp[100000];
void mergesort(int *a, int left, int right){
    if(left == right) {
    	return;
	}
    int mid = (left + right) / 2;
    mergesort(a,left,mid);
	mergesort(a,mid+1,right);
    int i = left, j = mid + 1,k = left;
    while(i <= mid && j <= right) {
    	if(a[i] <= a[j]) {
        	temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}  
    while(i <= mid) {
    	temp[k++] = a[i++];
	}
    while(j <= right) {
    	temp[k++] = a[j++];
	}
    for(int i = left;i <= right; i++) {
    	a[i] = temp[i];
	}
}
//mergesort(a,0,n-1)
```

### 冒泡排序

```c++
void bubblesort(int *a, int n) {
	int i, j, flag;
	for(i = 0;i < n - 1;++i) {
		flag = 0;
		for(j = 0;j < n - i - 1;++j) {
			if(a[j] > a[j+1]) {
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 1;
			}
		}
		if(!flag) {
			break;
		}
	}
}
//bubblesort(a, n)
```

### 树状数组

```c++
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
```

> 1 单点更新与区间求和

```c++
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

```

> 2 区间更新与单点求值

```c++
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
```

### 快速读入

```c++
inline int read() {
	register int x = 0, f = 1;
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
```

### 快速输出

```c++
inline void write(register int x) {
    if(x < 0) { 
  		putchar('-');
		x = -x;
	}
  	if(x > 9) {
  		write(x / 10);
	} 
    putchar(x % 10 + '0');
}
```



### 优先队列

```c++
#include<queue>  //p.top()
priority_queue <int, vector<int>, greater<int> > p;//从小到大
priority_queue <int> p; //从大到小
```

> 结构体_priority

```c++
#include<queue>
struct Node{
    int value;
    int key;
}p[10];
struct cmp{
    bool operator()(Node a,Node b){
        if(a.key == b.key){
            return a.value < b.value;
        }
        return a.key < b.key;      //注意与sort分开
    }							 
};
priority_queue<Node,vector<Node>,cmp> heap; //按第一关键字 从大到小排序
```

> 实现优先队列

```c++
#include <vector>
template <class type>
class priority_queue {
    private:
        vector<type> data;         
    public:
        void push(type t){ 
            data.push_back(t); 
            push_heap( data.begin(), data.end()); 
        }         
        void pop(){
            pop_heap( data.begin(), data.end() );
            data.pop_back();
        }         
        type top() { return data.front(); }
        int size() { return data.size(); }
        bool empty() { return data.empty(); }
};  
```

### 逆序数

> 给定一个数组A[0…N-1]，若对于某两个元素a[i]、a[j]，若i＜j且a[i]＞a[j]，则称(a[i],a[j])为逆序对。一个数组中包含的逆序对的数目称为该数组的逆序数。 

```c++
while(i <= mid && j <= right) {
		if(a[i] < a[j]) {
			temp[n++] = a[i++];
		} else {
			count += (mid - i + 1);  //修改归并排序的merge函数
			temp[n++] = a[j++];
		}
	}
//特别注意当输入多组数的时候count要初始化为0
```

### 最大公因数

```c++
int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a); 
} 
```

### 全排列

```c++
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
```



```c++
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
```

### 二分搜索

```c++
int binary_search(int* a, int len, int goal) {
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int middle = (high - low) / 2 + low; // 直接使用(high + low) / 2 可能导致溢出
        if (a[middle] == goal) {
        	return middle;
		} else if (a[middle] > goal) {
			high = middle - 1;
		} else {
			low = middle + 1;
		}
    }
    return -1;
}
```

### 并查集

```c++
int f[10010];
int find(int k){
    if(f[k] == k) {
    	return k;
	}
    return f[k] = find(f[k]);
}
void join(int x,int y) {
    int fx = find(x); 
	int fy = find(y);                                        
	f[fx] = fy;                      
}
for(int i = 1;i <= 100;++i) {
    f[i] = i;
}
//切记  f数组一定要初始化
```

### 前式链向星

```c++
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

```

### 最小生成树

> **kruskal**

```c++
int kruskal(int m, int n) { //m： 边的个数  n： 顶点数
	int num = 0, ans = 0;
    sort(p,p+m,cmp);
    for(int i = 0;i < m;i++) {
        int fu = find(p[i].u);
		int fv = find(p[i].v);
        if(fu == fv) {
            continue;
        }
        ans += p[i].w;
        f[fu] = fv;
        if(++num == n - 1) { //已连边个数是点个数-1时，停止循环，最小生成树完成
            break;
        }
    }
    return ans;
}
```

### 大根堆

```c++
int size = 0, heap[1000000];
void push(int e){
    heap[++size] = e;
    int son = size, father = son / 2;
    while(heap[son] > heap[father] && father >= 1){
        swap(heap[son],heap[father]);
        son = father,father = son / 2;
    }
}
void pop(){
    swap(heap[1],heap[size]);
    heap[size--]=0;
    int father = 1,son = 2;
    while(son <= size){
        if(son < size && heap[son] < heap[son+1]) son++;
        if(heap[father] < heap[son]){
            swap(heap[father],heap[son]);
            father = son, son = father * 2;
        }else break;
    }
}
int top(){
    return heap[1];
}
```

### 线性筛

```c++
bool is_prime[10000001];
int prime[10000001], cnt = 0;
void getprime(int n) {     // cnt  质数个数
						   // prime 存的是质数 2 3 5 7
						   // is_prime 存的是这个数是不是素数 真就是素数 
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
	is_prime[0] = 0;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
        	 prime[cnt++] = i; 
		}
        for(int j = 0; j < cnt && i * prime[j] <= n; j++)  {  
            is_prime[ i * prime[j]] = 0;
            if(i % prime[j] == 0) {
            	break; 
			}
        }
    }
}
```

### 栈

```c++
class _stack {
	private:
		int *top;
		int *base;
		int stacksize;
	public:
		int init();
		int _push(int e);
		int _pop();
		int _top();
		int _empty();
		int getlen();
		int destory();
};
int _stack::init() {
	base = (int*)malloc(sizeof(int));
	if(!base) {
		exit(0);
	}
	top = base;
	stacksize = 1;
	return 1;
}
int _stack::_push(int e) {
	int *p;
	if(top - base >= stacksize) {
		p = (int*)realloc(base,(stacksize + 1) * sizeof(int));
		if(!p) {
			exit(0);
		}
		base = p; 
		top = base + stacksize;
		stacksize++;
	}
	*top = e;
	top++;
	return 1;
} 
int _stack::_pop() {
	if(top == base) {
		return 0;
	}
	--top;
}
int _stack::_top() {
	if(base == top) {
		return 0;
	}
	return *(top - 1);
}
int _stack::_empty() {
	return top == base;
}
int _stack::getlen() {
	return top - base;
}
int _stack::destory() {
	if(!stacksize) {
		exit(0);
	}
	free(base);
	stacksize = 1;
	return 1;
}
```

### 队列

```c++
struct node {
	int data;
	struct node* next;
};
class linkqueue {
	private:
		node *front;
		node *rear;
	public:
		int init();
		int _push(int e);
		int _pop();
		int _top();
		int _empty();
		int destory();
};
int linkqueue::init() {
	front = (node*)malloc(sizeof(node));
	if(!front) {
		exit(0);
	}
	front -> next = NULL;
	rear = front;
	return 1;
}
int linkqueue::_push(int e) {
	node *p;
	p = (node*)malloc(sizeof(node));
	if(!p) {
		exit(0);
	}
	p -> data = e;
	p -> next = NULL;
	rear -> next = p;
	rear = p;
	return 1;
} 
int linkqueue::_pop() {
	node *p;
	if(front == rear) {
		return 0;
	}
	p = front -> next;
	front -> next = p -> next;
	if(p == rear) {
		rear = front;
	}
	free(p);
	return 1;
}
int linkqueue::_top() {
	if(front == rear) {
		return 0;
	}
	return front -> next -> data;
}
int linkqueue::_empty() {
	return front == rear;
}
int linkqueue::destory() {
	while(front) {
		rear = front -> next;
		free(front);
		front = rear;
	}
}
```

###  π   acos(-1.0)

### 不用加减乘除做加法

```c++
int p(int a,int b) {
    if(b == 0) { //如果b(进位)是0(没有进位了)，返回a的值
    	return a;
	} else{
        int x, y;
        x = a ^ b; //x是a和b不进位加法的值
        y = (a & b) << 1;//y是a和b进位的值(左移一位是进位加在左面一位)
        return p(x, y);//把不进位加法和进位的值的和就是结果
    }
}
```

### 文件操作

> **创建并打开一个文本文档  -> 左上角文件 另存为 -> 下面选择所有文件 -> 输入文件名**
>
> **data.in 里要提前保存样例  输出结果在data.out中**



```c
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
```

### 比赛中要求用文件输入输出 但禁止用重定向版本

```c
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
```

