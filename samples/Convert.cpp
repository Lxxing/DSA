/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
using namespace std;

#include <string>
#include <stack>

//十进制正整数n到base进制的转换

static const char baseNum[] = 
	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };


void convert ( std::stack<char>& S, __int64 n, int base )
{
	while (n > 0)
	{
		int remainder = n % base;
		S.push(baseNum[remainder]);
		n = n / base;
	}

}
void convertR ( std::stack<char>& S, __int64 n, int base )
{
	if (n > 0)
	{
		int remainder = n % base;
		S.push(baseNum[remainder]);
		n = n / base;
		convertR(S, n, base);
	}

}

void main()
{

	int testnum = 5864;
	std::stack<char> rnt;
	convert(rnt,testnum,8);//13350
	while (!rnt.empty())
	{
		std::cout << rnt.top();
		rnt.pop();
	}
	std::cout << std::endl;
	convert(rnt,testnum,2);//1011011101000
	while (!rnt.empty())
	{
		std::cout << rnt.top();
		rnt.pop();
	}

}

