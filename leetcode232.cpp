class MyQueue {
public:
    stack<int> _temp;
    stack<int> _main;
    
    MyQueue() {
    }
    
    void push(int x) {
        _temp.push(x);
        stack<int> _t = _temp;
        stack<int> _a;
        while(!_t.empty()){
            _a.push(_t.top());
            _t.pop();
        }
        _main = _a;
    }
    
    int pop() {
        int target = _main.top();
        _main.pop();
        stack<int> _a = _main;
        stack<int> _t;
        while(!_a.empty()){
            _t.push(_a.top());
            _a.pop();
        }
        _temp = _t;
        return target;
    }
    
    int peek() {
        
        return _main.top();
    }
    
    bool empty() {
        if(_main.empty())
            return true;
        return false;
    }
};

/*            _temp()  _main()
   push 1. -> _temp(1)  _main(1) 
   push 2. -> _temp(2,1) -> _main(1,2)
   push 3. -> _temp(3,2,1) -> _main(1,2,3)
      = 
                    
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
