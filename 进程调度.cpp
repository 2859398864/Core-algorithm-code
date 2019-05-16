#include<iostream>
#include<queue>
#include<cstdio> 
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
queue <char> now;
queue <char> later;
char cpu = ' ';
int nowid;
int laterid;
void creat() {
	char input;
	cout<<"输入进程名称:";
    cin>>input;
	now.push(input); 
}
void do_p() {
	if(cpu == ' ') {
		if(now.empty() ) {
			cout<<"就绪队列为空"<<endl;
			
		} else {
			cpu = now.front() ;
			now.pop() ;
		}
		
	} else {
		cout<<"cpu 正在处理进程"<<endl;;
	}
}
char nowarray[100];
char laterarray[100];
void print() {
	nowid = 0;
	laterid = 0;
	cout<<"就绪队列进程 : ";
	while(!now.empty() ) {
		cout<<now.front() <<" ";
		nowarray[nowid++] = now.front() ;
		now.pop() ;
	}
	for(int i = 0;i < nowid;++i) {
		now.push(nowarray[i]); 
	}
	cout<<endl;
	cout<<"阻塞队列进程 : ";
	while(!later.empty() ) {
		cout<<later.front() <<" ";
		laterarray[laterid++] = later.front() ;
		later.pop() ;
	}
	for(int i = 0;i < laterid;++i) {
		later.push(laterarray[i]); 
	}
	cout<<endl;
	cout<<"cpu :"<<cpu<<endl;;
}
int a;
int main() {
	
	char c;
	
	while(c = getchar()) {
		switch(c) {
			
			case 'r':
			case 'R':
				srand((unsigned long)time(0));	
				a = rand()%7 + 1;
				switch(a) {
					case 1:
						cout<<"创建进程"<<endl;
						creat();
						break;
					case 2:
						cout<<"调入进程"<<endl;
						do_p();
						break;
					case 3:
						cout<<"结束进程"<<endl;
						cpu = ' ';
						break;
					case 4:
						cout<<"阻塞进程"<<endl;
						if(cpu == ' ') break;
						later.push(cpu);
						cpu = ' ';
						break;
					case 5:
						cout<<"唤醒进程"<<endl;
						if(later.empty() ) {
							cout<<"阻塞队列进程为空"<<endl;
						} else {
							now.push(later.front() );
							later.pop() ;
						}
						break;
					case 7:
						cout<<"显示进程状态"<<endl;
						print();
						break;
					case 6:
						cout<<"时间片到"<<endl;
						now.push(cpu);
						cpu = ' ';
						break;
						
				}
				break;
			case '#':
				return 0;
				break;
			case 'H':
			case 'h':
				cout<<"H   帮助命令 ，可以显示所有的允许命令及功能"<<endl;
				cout<<"C   创建进程。 必须输入一个字符作为进程的名字"<<endl;
				cout<<"P   调入进程。 将就绪队列的进程调入cpu"<<endl;
				cout<<"E   结束进程。 将cpu中的进程结束。"<<endl;
				cout<<"B   阻塞进程。 将cpu中的进程插入阻塞队列。"<<endl;
				cout<<"W   唤醒进程。 将阻塞队列中的进程插入就绪队列。"<<endl;
				cout<<"T   时间片到。 将cpu中的进程插入就绪队列。"<<endl;
				cout<<"S   显示进程状态。 显示各个队列中的进程。"<<endl;
				cout<<"Enter  按回车执行随机命令。"<<endl;
				cout<<"#   退出试验程序。"<<endl;
				break;
			case 'C':
			case 'c':
				 creat();
				 break;
			case 'p':
			case 'P':
				do_p();
				break;
			case 'E':
			case 'e':
				cpu = ' ';
				break;
			case 'b':
			case 'B':
				later.push(cpu);
				cpu = ' ';
				break;
			case 'w':
			case 'W':
				if(later.empty() ) {
					cout<<"阻塞队列进程为空"<<endl;
				} else {
					now.push(later.front() );
					later.pop() ;
				}
				break;
			case 't':
			case 'T':
				now.push(cpu);
				cpu = ' ';
				break;
			case 's':
			case 'S':
				print();
				break;
			
		}
		c = getchar();
	}
}
