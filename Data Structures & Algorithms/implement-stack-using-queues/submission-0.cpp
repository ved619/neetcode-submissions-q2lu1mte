class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        //step1: push normally
        q.push(x);
        //step2:rotate previous elements
        int n=q.size();
        for(int i=0;i<n-1;++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement=q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */