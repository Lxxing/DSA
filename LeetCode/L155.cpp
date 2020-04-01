/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "LeetCode.h"
/**********
使用两个栈更简单，一个存储最小值的栈，可能有多个值。跟随栈的数量变化
只使用一个栈，要考虑数量变化时的最小值变化，push/pop。相当于两个栈的数据全放到一个栈中实现
************/
class MinStack1{
public:
    /** initialize your data structure here. */
    MinStack1() {
		minValue = INT_MAX;
    }
    
    void push(int x) {
		//minValue = min(x,minValue);错误，之前的最小值信息丢失
		//插入最小值时，放入重复最小值信息。如果此处不加=，那么出栈时需要使用小于等于号
		//if (x <= minValue )
		if (x <= minValue)
		{
			stackAll.push(minValue);
			minValue = x;
		}
		stackAll.push(x);
    }
    
    void pop() {
    	int num = stackAll.top();
		stackAll.pop();//判断出栈数据是否需要改动最小值
		if (num <= minValue)
		{
			num = stackAll.top();
			minValue = num;
			stackAll.pop();
		}
    }
    
    int top() {
		return stackAll.top();
    }
    
    int getMin() {
		return minValue;
    }

private:
    stack<int> stackAll;
    int minValue;
};
class MinStack{
public:
    /** initialize your data structure here. */
    MinStack() {
    	stackMin.push(INT_MAX);
    }
    
    void push(int x) {
		if (x <= stackMin.top())
		{
			stackMin.push(x);
		}
		stackAll.push(x);
    }
    
    void pop() {
    	int num = stackAll.top();
		stackAll.pop();//判断出栈数据是否需要改动最小值
		if (num <= stackMin.top())
		{
			stackMin.pop();
		}
    }
    
    int top() {
		return stackAll.top();
    }
    
    int getMin() {
		return stackMin.top();
    }

private:
    stack<int> stackAll;
    stack<int> stackMin;
};

void main()
{
	MinStack *minStack = new MinStack();
	//0,1,0
	//-2,0,-3
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	minStack->getMin();	 
	minStack->pop();
	minStack->top(); 	 
	minStack->getMin();	 
	delete minStack;
}

