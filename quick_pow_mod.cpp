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
int qpowmod(ll a, ll b, ll m) {
    ll ans = 1, base = a % m;
    while(b > 0) {
        if(b & 1) {
            ans = ans * base % m;
        }
        base = base * base % m;
        b >>= 1;
    }
    return ans % m;
}
int main() {
	ll a, b, m;
	a = read();
	b = read();
	m = read();
	ll c = qpowmod(a,b,m);
	cout<<a<<"^"<<b<<" mod "<<m<<"="<<c;
    return 0;
} 
