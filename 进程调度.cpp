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
	cout<<"�����������:";
    cin>>input;
	now.push(input); 
}
void do_p() {
	if(cpu == ' ') {
		if(now.empty() ) {
			cout<<"��������Ϊ��"<<endl;
			
		} else {
			cpu = now.front() ;
			now.pop() ;
		}
		
	} else {
		cout<<"cpu ���ڴ������"<<endl;;
	}
}
char nowarray[100];
char laterarray[100];
void print() {
	nowid = 0;
	laterid = 0;
	cout<<"�������н��� : ";
	while(!now.empty() ) {
		cout<<now.front() <<" ";
		nowarray[nowid++] = now.front() ;
		now.pop() ;
	}
	for(int i = 0;i < nowid;++i) {
		now.push(nowarray[i]); 
	}
	cout<<endl;
	cout<<"�������н��� : ";
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
						cout<<"��������"<<endl;
						creat();
						break;
					case 2:
						cout<<"�������"<<endl;
						do_p();
						break;
					case 3:
						cout<<"��������"<<endl;
						cpu = ' ';
						break;
					case 4:
						cout<<"��������"<<endl;
						if(cpu == ' ') break;
						later.push(cpu);
						cpu = ' ';
						break;
					case 5:
						cout<<"���ѽ���"<<endl;
						if(later.empty() ) {
							cout<<"�������н���Ϊ��"<<endl;
						} else {
							now.push(later.front() );
							later.pop() ;
						}
						break;
					case 7:
						cout<<"��ʾ����״̬"<<endl;
						print();
						break;
					case 6:
						cout<<"ʱ��Ƭ��"<<endl;
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
				cout<<"H   �������� ��������ʾ���е������������"<<endl;
				cout<<"C   �������̡� ��������һ���ַ���Ϊ���̵�����"<<endl;
				cout<<"P   ������̡� ���������еĽ��̵���cpu"<<endl;
				cout<<"E   �������̡� ��cpu�еĽ��̽�����"<<endl;
				cout<<"B   �������̡� ��cpu�еĽ��̲����������С�"<<endl;
				cout<<"W   ���ѽ��̡� �����������еĽ��̲���������С�"<<endl;
				cout<<"T   ʱ��Ƭ���� ��cpu�еĽ��̲���������С�"<<endl;
				cout<<"S   ��ʾ����״̬�� ��ʾ���������еĽ��̡�"<<endl;
				cout<<"Enter  ���س�ִ��������"<<endl;
				cout<<"#   �˳��������"<<endl;
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
					cout<<"�������н���Ϊ��"<<endl;
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
