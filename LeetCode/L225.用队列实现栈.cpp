/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
		topValue = INT_MIN;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		queuePush.push(x);
		topValue = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		while (queuePush.size() > 2)
		{
			int item = queuePush.front();
			queuePush.pop();
			queuePop.push(item);
		}
		if (queuePush.size() == 2)
		{		
			topValue = queuePush.front();
			queuePush.pop();
			queuePop.push(topValue);
		}
		int result = queuePush.front();
		queuePush.pop();
		queuePush.swap(queuePop);
		
		return result;
    }
    
    /** Get the top element. */
    int top() {
		return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return queuePush.empty();
    }
private:
    queue<int> queuePush;
    queue<int> queuePop;//可以用queue的出队接口优化掉，循环出队入队(n-1)
    int topValue;
};


void main()
{
	MyStack* obj = new MyStack();
	obj->push(x);
	int param_2 = obj->pop();
	int param_3 = obj->top();
	bool param_4 = obj->empty();
}
