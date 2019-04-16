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
