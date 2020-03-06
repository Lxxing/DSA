/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

#include "LXDefine.h"

Operator Optr2Rank ( char op ) 
{ //由运算符转译出编号
   switch ( op ) {
      case '+' : return ADD; //加
      case '-' : return SUB; //减
      case '*' : return MUL; //乘
      case '/' : return DIV; //除
      case '^' : return POW; //乘方
      case '!' : return FAC; //阶乘
      case '(' : return L_P; //左括号
      case ')' : return R_P; //右括号
      case '\0': return EOE; //起始符与终止符
      default  : exit ( -1 ); //未知运算符
   }
}

char OrderBetween(char stackOper,char currentOper)
{
	return operPriority[Optr2Rank(stackOper)][Optr2Rank(currentOper)];
}
float calcu ( char op,float a, float b ) 
{ //执行二元运算
   switch ( op ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b;
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}
void ReadNumber( string::iterator&pHead, stack<float>& S)
{
	S.push((float)(*pHead - '0'));
	pHead++;
	while (isdigit(*pHead))//整数部分
	{
		float item = S.top();
		S.pop();
		S.push(item * 10 + (float)(*pHead - '0'));
		pHead++;
	}
	//小数判断
	if (*pHead == '.')
	{
		pHead++;
	}
	else
	{
		return;
	}
	while (isdigit(*pHead))//小数部分
	{
		float item = S.top();
		S.pop();
		float fraction = 1.0;//小数
		fraction /= 10;
		S.push(item + (float)(*pHead - '0') * fraction);
		pHead++;
	}//整数部分
	
}

//表达式expr不含空格，rpn输出
float PRNEvaluate ( string expr, string& rpn )
{
	string::iterator pHead = expr.begin();
	stack<float> mOperand;
	stack<char> mOperator;

	mOperator.push('\0');//字符串起始位哨兵

	while (!mOperator.empty())
	{
		if ((pHead != expr.end()) && isdigit(*pHead))//尾哨兵判断
		{//支持多位数或者小数需要增加数据读取函数
			/*const char pnum = *pHead;
			float num = atof(&pnum);
			mOperand.push(num);
			pHead++;
			rpn.push_back(pnum);
			*/
			ReadNumber(pHead,mOperand);
			char buf[64];
			float opnd = mOperand.top();
   			if ( opnd != ( float ) ( int ) opnd ) 
   			    sprintf ( buf, "%.2f \0", opnd ); //浮点格式，或
   			else                          
   			    sprintf ( buf, "%d \0", ( int ) opnd ); //整数格式
			string tmp(buf);
			rpn.append(tmp);
		}
		else
		{//比较操作符优先级
			char stackOper = mOperator.top();
			char ord;
			if(pHead == expr.end())
			{
				ord = OrderBetween(stackOper, '\0');//尾哨兵不能取值
			}
			else
			{
				ord = OrderBetween(stackOper,*pHead);
			}
		
			switch (ord)
			{
				case '<'://当前优先级高,延迟计算.栈顶为‘(’时，所有入栈。知道遇到‘)’，逐一弹出操作符
					mOperator.push(*pHead);
					pHead++;
					break;
				case '='://括号或者结束符
					mOperator.pop();
					if (pHead != expr.end())
					{
						pHead++;
					}
					
					break;
				case '>'://运算
					char operator1 = mOperator.top();
					rpn.push_back(operator1);
					mOperator.pop();

					float oper1 = mOperand.top();//后操作符
					mOperand.pop();
					if (stackOper == '!')
					{
						//阶乘函数
					}
					else
					{
						float oper2 = mOperand.top();//前操作符
						mOperand.pop();
						float rnt = calcu(operator1,oper2,oper1);
						mOperand.push(rnt);
					}
					break;
				
			}
		}
	}

	return mOperand.top();
}


void main()
{

	string exp = "(1+(2+3))/6*5*4-(7+8+9)";
	string prn;

	cout << "PRNEvaluate:" << PRNEvaluate(exp,prn) << endl
		<< "prn:" << prn << endl;

	exp = "(1.1+(2+3))/6*5*4-(70+8+9)";
	prn = "";
	cout << "PRNEvaluate:" << PRNEvaluate(exp, prn) << endl
		<< "prn:" << prn << endl;
}


