/******************************************************************************************
* RMQ4CPP 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/


#include <iostream>
#include <stack>
using namespace std;

//S = S0 + "(" + S1 + ")" + S2 + S3��S0��S3��������
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
	int count = 1;//���Ų�
	while (++mid <= hi)//�Ⱥ���Ҫ�������ٵ������������
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
	StrTrim(exp,lo,hi);//ȥ����Ч�ַ�
	//�ݹ��
	if(lo > hi) return true;//���ܵ��ڣ������д��ڲ�ƥ������

	//��ƥ��ʧ�����
	if(exp[lo] != '(') return false;
	if(exp[hi] != ')') return false;
	
	int mid = partition(exp,lo,hi);//�зֵ�
	if (mid < 0) return false;

    return ParenCheck(exp, lo + 1, mid - 1) && 
    		ParenCheck(exp, mid + 1, hi);
}
//ʹ�ö�ջ
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
			case ')'://SΪ�գ�top�����쳣
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


