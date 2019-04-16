#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef long long int ll; 
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' && ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int qpow(ll a, ll b) {
    ll ans = 1, base = a;
    while(b > 0) {
        if(b & 1) {
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }
    return ans;
}
int main() {
	ll a, b;
	a = read();
	b = read();
	ll c = qpow(a,b);
	cout<<c;
    return 0;
} 
