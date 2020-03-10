/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/

#include "LeetCode.h"
/**********
ʹ������ջ���򵥣�һ���洢��Сֵ��ջ�������ж��ֵ������ջ�������仯
ֻʹ��һ��ջ��Ҫ���������仯ʱ����Сֵ�仯��push/pop���൱������ջ������ȫ�ŵ�һ��ջ��ʵ��
************/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
		minValue = INT_MAX;
    }
    
    void push(int x) {
		//minValue = min(x,minValue);����֮ǰ����Сֵ��Ϣ��ʧ
		//������Сֵʱ�������ظ���Сֵ��Ϣ������˴�����=����ô��ջʱ��Ҫʹ��С�ڵ��ں�
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
		stackAll.pop();//�жϳ�ջ�����Ƿ���Ҫ�Ķ���Сֵ
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

