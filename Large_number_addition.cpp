#include<iostream>
#include<cstdio>
using namespace std;

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
int main() {
	string a, b;
	cin>>a>>b;
	cout<<add(a,b);
	return 0;
}
