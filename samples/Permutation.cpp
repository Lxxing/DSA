/******************************************************************************************
* RMQ4CPP 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/


#include <iostream>
#include <stack>
using namespace std;

//S = S0 + "(" + S1 + ")" + S2 + S3。S0与S3不含括号
void StrTrim(char exp[],int &lo,int &hi)
{
	while ((exp[lo] != '(') && (exp[lo] != ')') && (lo <= hi))
	{
		lo++;
	}
	while ((exp[hi] != '(') && (exp[hi] != ')') && (lo <= hi))
	{
		hi--;
	}
}
int partition(char exp[],int lo,int hi)
{
	int mid = lo;
	int count = 1;//括号差
	while (++mid <= hi)//等号需要包括最少的两个括号情况
	{
		if (exp[mid] == '(')
		{
			count++;
		}
		if (exp[mid] == ')')
		{
			count--;
		}
		if (count == 0)
		{
			return mid;
		}
	}
	return -1;
}

bool ParenCheck(char exp[],int lo,int hi)
{
	StrTrim(exp,lo,hi);//去掉无效字符
	//递归基
	if(lo > hi) return true;//不能等于，子序列存在不匹配的情况

	//不匹配失败情况
	if(exp[lo] != '(') return false;
	if(exp[hi] != ')') return false;
	
	int mid = partition(exp,lo,hi);//切分点
	if (mid < 0) return false;

    return ParenCheck(exp, lo + 1, mid - 1) && 
    		ParenCheck(exp, mid + 1, hi);
}
//使用堆栈
bool ParenCheckStack(char exp[],int lo,int hi)
{
	stack<char> S;
	while (lo < hi)
	{
		char item = exp[lo++];
		switch (item)
		{
			case '(':
			case '{':
			case '[':
				S.push(item);
				break;
			case ')'://S为空，top函数异常
				if((!S.empty()) && ('(' == S.top()))
				{
					S.pop();
				}
				else
				{
					return false;
				}
				
				break;
			case '}':
				if((!S.empty()) && ('{' == S.top()))
				{
					S.pop();
				}
				else
				{
					return false;
				}
				break;
			case ']':
				if((!S.empty()) && ('[' == S.top()))
				{
					S.pop();
				}
				else
				{
					return false;
				}
				break;
		    default:
				break;

		}
	}

	return S.empty();

}

void main()
{
	char exp[]="a/(b[i-1][j+1]+c[i+1][j-1])*2";
	cout << "ParenCheckStack:" << ParenCheckStack(exp,0,strlen(exp) - 1) << endl;
	cout << ":" << ParenCheck(exp,0,strlen(exp) - 1) << endl;
	char exp1[]="a/(b[i-1][j+1])+c[i+1][j-1])*2";
	cout << "ParenCheckStack:" << ParenCheckStack(exp1, 0, strlen(exp) - 1) << endl;
	cout << ":" << ParenCheck(exp1,0,strlen(exp1) - 1) << endl;
}


