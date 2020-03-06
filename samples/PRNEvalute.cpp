/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

#include "LXDefine.h"

Operator Optr2Rank ( char op ) 
{ //�������ת������
   switch ( op ) {
      case '+' : return ADD; //��
      case '-' : return SUB; //��
      case '*' : return MUL; //��
      case '/' : return DIV; //��
      case '^' : return POW; //�˷�
      case '!' : return FAC; //�׳�
      case '(' : return L_P; //������
      case ')' : return R_P; //������
      case '\0': return EOE; //��ʼ������ֹ��
      default  : exit ( -1 ); //δ֪�����
   }
}

char OrderBetween(char stackOper,char currentOper)
{
	return operPriority[Optr2Rank(stackOper)][Optr2Rank(currentOper)];
}
float calcu ( char op,float a, float b ) 
{ //ִ�ж�Ԫ����
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
	while (isdigit(*pHead))//��������
	{
		float item = S.top();
		S.pop();
		S.push(item * 10 + (float)(*pHead - '0'));
		pHead++;
	}
	//С���ж�
	if (*pHead == '.')
	{
		pHead++;
	}
	else
	{
		return;
	}
	while (isdigit(*pHead))//С������
	{
		float item = S.top();
		S.pop();
		float fraction = 1.0;//С��
		fraction /= 10;
		S.push(item + (float)(*pHead - '0') * fraction);
		pHead++;
	}//��������
	
}

//���ʽexpr�����ո�rpn���
float PRNEvaluate ( string expr, string& rpn )
{
	string::iterator pHead = expr.begin();
	stack<float> mOperand;
	stack<char> mOperator;

	mOperator.push('\0');//�ַ�����ʼλ�ڱ�

	while (!mOperator.empty())
	{
		if ((pHead != expr.end()) && isdigit(*pHead))//β�ڱ��ж�
		{//֧�ֶ�λ������С����Ҫ�������ݶ�ȡ����
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
   			    sprintf ( buf, "%.2f \0", opnd ); //�����ʽ����
   			else                          
   			    sprintf ( buf, "%d \0", ( int ) opnd ); //������ʽ
			string tmp(buf);
			rpn.append(tmp);
		}
		else
		{//�Ƚϲ��������ȼ�
			char stackOper = mOperator.top();
			char ord;
			if(pHead == expr.end())
			{
				ord = OrderBetween(stackOper, '\0');//β�ڱ�����ȡֵ
			}
			else
			{
				ord = OrderBetween(stackOper,*pHead);
			}
		
			switch (ord)
			{
				case '<'://��ǰ���ȼ���,�ӳټ���.ջ��Ϊ��(��ʱ��������ջ��֪��������)������һ����������
					mOperator.push(*pHead);
					pHead++;
					break;
				case '='://���Ż��߽�����
					mOperator.pop();
					if (pHead != expr.end())
					{
						pHead++;
					}
					
					break;
				case '>'://����
					char operator1 = mOperator.top();
					rpn.push_back(operator1);
					mOperator.pop();

					float oper1 = mOperand.top();//�������
					mOperand.pop();
					if (stackOper == '!')
					{
						//�׳˺���
					}
					else
					{
						float oper2 = mOperand.top();//ǰ������
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


