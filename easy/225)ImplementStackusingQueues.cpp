class MyStack {
    queue<int> que;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
    }
    
    int pop() {
        int temp =  que.front();
        que.pop();
        return temp;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};