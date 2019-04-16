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
