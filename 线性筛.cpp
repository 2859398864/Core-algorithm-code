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
