
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include "LeetCode.h"


class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
		while (!stackPop.empty())
		{
			int item = stackPop.top();
			stackPop.pop();
			stackPush.push(item);
		}
		stackPush.push(value);
    }
    
    int deleteHead() {
		while (!stackPush.empty())
		{
			int item = stackPush.top();
			stackPush.pop();
			stackPop.push(item);
		}
		int resuslt = -1;
		if (!stackPop.empty())
		{
			resuslt = stackPop.top();
			stackPop.pop();
		}
		return resuslt;
    }
private:
	stack<int> stackPush;
	stack<int> stackPop;
};

class MyQueue {
public:
    
    /** Push element x to the back of queue. */
    void push(int x) {
		stackPush.push(x);
		if (stackPush.size() == 1)
		{
			frontValue = x;
		}
		
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		while (stackPush.size() > 0)
		{
			int item = stackPush.top();
			stackPush.pop();
			stackPop.push(item);
		}
		int result = INT_MIN;
		if (stackPop.size())
		{
			result = stackPop.top();
			stackPop.pop();
			
		}
		if (stackPop.size())
		{
			frontValue = stackPop.top();		
		}
		
		while (stackPop.size())
		{
			int item = stackPop.top();
			stackPop.pop();
			stackPush.push(item);
		}
		return result;
    }
    
    /** Get the front element. */
    int peek() {
		return frontValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return stackPush.empty();
    }
private:
	int frontValue;
	stack<int> stackPush;
	stack<int> stackPop;
};

class MyQueue2 {
public:
    
    /** Push element x to the back of queue. */
    void push(int x) {
		stackPush.push(x);
		if (stackPush.size() == 1)
		{
			frontValue = x;
		}
		
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		while (stackPush.size() > 1)
		{
			int item = stackPush.top();
			stackPush.pop();
			stackPop.push(item);
		}
		if (stackPop.size())
		{
			frontValue = stackPop.top();
		}
		
		int result = stackPush.top();
		stackPush.pop();
		while (stackPop.size())
		{
			int item = stackPop.top();
			stackPop.pop();
			stackPush.push(item);
		}
		return result;
    }
    
    /** Get the front element. */
    int peek() {
		return frontValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return stackPush.empty();
    }
private:
	int frontValue;
	stack<int> stackPush;
	stack<int> stackPop;
};

 
void main()
{
	MyQueue* obj = new MyQueue();
	obj->push(x); 
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();
}
