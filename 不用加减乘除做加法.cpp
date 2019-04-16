π   acos(-1.0)

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
