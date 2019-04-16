#include<queue>  //p.top()
priority_queue <int, vector<int>, greater<int> > p;//从小到大
priority_queue <int> p; //从大到小

结构体_priority

#include<queue>
struct Node{
    int value;
    int key;
}p[10];
struct cmp{
    bool operator()(Node a,Node b){
        if(a.key == b.key){
            return a.value < b.value;
        }
        return a.key < b.key;      //注意与sort分开
    }							 
};
priority_queue<Node,vector<Node>,cmp> heap; //按第一关键字 从大到小排序


实现优先队列

#include <vector>
template <class type>
class priority_queue {
    private:
        vector<type> data;         
    public:
        void push(type t){ 
            data.push_back(t); 
            push_heap( data.begin(), data.end()); 
        }         
        void pop(){
            pop_heap( data.begin(), data.end() );
            data.pop_back();
        }         
        type top() { return data.front(); }
        int size() { return data.size(); }
        bool empty() { return data.empty(); }
};  
