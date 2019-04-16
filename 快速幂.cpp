sum = 2 ^ n   sumµÄÎ»Êı   n * log10(2) + 1
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
